import { existsSync } from "node:fs";
import {
  mkdir,
  readFile,
  readdir,
  rename,
  writeFile,
} from "node:fs/promises";
import { execFileSync } from "node:child_process";
import path from "node:path";
import { fileURLToPath } from "node:url";
import { reconcileSourceReadme } from "./reconcile-source-readmes.mjs";

const INDEX_START = "<!-- til-studio:index:start -->";
const INDEX_END = "<!-- til-studio:index:end -->";

export async function planSourceMigration(repositoryRoot, sourceRoot) {
  const absoluteSource = path.join(repositoryRoot, sourceRoot);
  const entries = await readdir(absoluteSource, { withFileTypes: true });
  const moves = [];

  for (const entry of entries) {
    const normalizedName = stripControlCharacters(entry.name);
    let destinationName = "";

    if (entry.isDirectory() && normalizedName.toLowerCase() === "code") {
      destinationName = "src";
    } else if (
      entry.isFile() &&
      normalizedName.toLowerCase() === "readme.md" &&
      entry.name !== "README.md"
    ) {
      destinationName = "README.md";
    } else if (
      entry.isFile() &&
      entry.name.endsWith(".md") &&
      entry.name.toLowerCase() !== "readme.md"
    ) {
      destinationName = `note/${entry.name}`;
    }

    if (!destinationName) continue;
    const from = path.posix.join(sourceRoot, entry.name);
    const to = path.posix.join(sourceRoot, destinationName);
    if (existsSync(path.join(repositoryRoot, to))) {
      throw new Error(`migration destination already exists: ${to}`);
    }
    moves.push({ from, to });
  }

  return {
    sourceRoot,
    moves: moves.sort((left, right) => left.from.localeCompare(right.from)),
    noteDates: await collectNoteDates(repositoryRoot, sourceRoot, entries),
  };
}

export async function migrateRepository(repositoryRoot, options = {}) {
  const sourceRoots = await discoverSourceRoots(repositoryRoot);
  const plans = [];

  for (const sourceRoot of sourceRoots) {
    plans.push(await planSourceMigration(repositoryRoot, sourceRoot));
  }

  if (options.dryRun) {
    return {
      sourceCount: sourceRoots.length,
      moves: plans.flatMap((plan) => plan.moves),
    };
  }

  for (const plan of plans) {
    for (const move of plan.moves) {
      await mkdir(path.dirname(path.join(repositoryRoot, move.to)), {
        recursive: true,
      });
      await rename(
        path.join(repositoryRoot, move.from),
        path.join(repositoryRoot, move.to),
      );
    }

    await normalizeReadme(repositoryRoot, plan.sourceRoot);
    await addCreatedFrontmatter(repositoryRoot, plan.sourceRoot, plan.noteDates);
    await reconcileSourceReadme(repositoryRoot, plan.sourceRoot);
  }

  for (const topicRoot of await discoverTopicRoots(repositoryRoot)) {
    await reconcileTopicReadme(repositoryRoot, topicRoot);
  }

  return {
    sourceCount: sourceRoots.length,
    moves: plans.flatMap((plan) => plan.moves),
  };
}

async function discoverSourceRoots(repositoryRoot) {
  const roots = [];

  async function walk(relativeDirectory) {
    const absoluteDirectory = path.join(repositoryRoot, relativeDirectory);
    const entries = await readdir(absoluteDirectory, { withFileTypes: true });

    for (const entry of entries) {
      if (!entry.isDirectory() || entry.name === ".git") continue;
      const child = path.posix.join(relativeDirectory, entry.name);
      if (entry.name === "notes") {
        const sourceEntries = await readdir(path.join(repositoryRoot, child), {
          withFileTypes: true,
        });
        for (const sourceEntry of sourceEntries) {
          if (sourceEntry.isDirectory()) {
            roots.push(path.posix.join(child, sourceEntry.name));
          }
        }
        continue;
      }
      await walk(child);
    }
  }

  await walk("");
  return roots.sort((left, right) => left.localeCompare(right));
}

async function collectNoteDates(repositoryRoot, sourceRoot, sourceEntries) {
  const absoluteSource = path.join(repositoryRoot, sourceRoot);
  const readmeEntry = sourceEntries.find(
    (entry) =>
      entry.isFile() &&
      stripControlCharacters(entry.name).toLowerCase() === "readme.md",
  );
  const dates = readmeEntry
    ? datesFromLegacyReadme(
        await readFile(path.join(absoluteSource, readmeEntry.name), "utf8"),
      )
    : new Map();
  const candidates = [];
  const noteDirectory = path.join(absoluteSource, "note");

  if (existsSync(noteDirectory)) {
    const noteEntries = await readdir(noteDirectory, { withFileTypes: true });
    for (const entry of noteEntries) {
      if (entry.isFile() && entry.name.endsWith(".md")) {
        candidates.push({
          slug: entry.name.slice(0, -3),
          path: path.posix.join(sourceRoot, "note", entry.name),
        });
      }
    }
  }

  for (const entry of sourceEntries) {
    if (
      entry.isFile() &&
      entry.name.endsWith(".md") &&
      stripControlCharacters(entry.name).toLowerCase() !== "readme.md"
    ) {
      candidates.push({
        slug: entry.name.slice(0, -3),
        path: path.posix.join(sourceRoot, entry.name),
      });
    }
  }

  for (const candidate of candidates) {
    if (!dates.has(candidate.slug)) {
      const gitDate = gitCreationDate(repositoryRoot, candidate.path);
      if (gitDate) dates.set(candidate.slug, gitDate);
    }
  }

  return dates;
}

function datesFromLegacyReadme(content) {
  const dates = new Map();
  for (const line of content.split(/\r?\n/)) {
    const date = line.match(/^\|\s*(\d{4}-\d{2}-\d{2})\s*\|/)?.[1];
    const notePath = line.match(/\.\/note\/([^/)]+)\.md/)?.[1];
    if (date && notePath) dates.set(decodeURI(notePath), date);
  }
  return dates;
}

function gitCreationDate(repositoryRoot, filePath) {
  try {
    return execFileSync(
      "git",
      ["log", "--follow", "--diff-filter=A", "--format=%as", "--", filePath],
      { cwd: repositoryRoot, encoding: "utf8", stdio: ["ignore", "pipe", "ignore"] },
    )
      .trim()
      .split(/\r?\n/)
      .filter(Boolean)
      .at(-1) ?? "";
  } catch {
    return "";
  }
}

async function normalizeReadme(repositoryRoot, sourceRoot) {
  const readmePath = path.join(repositoryRoot, sourceRoot, "README.md");
  if (!existsSync(readmePath)) return;
  const existing = await readFile(readmePath, "utf8");
  const next = removeLegacyLearningLog(existing)
    .replaceAll("./code/", "./src/")
    .replace(/\(\.\.\/README\.md\)/g, "(../../README.md)");
  if (next !== existing) await writeFile(readmePath, next);
}

function removeLegacyLearningLog(content) {
  return content.replace(
    /\n##\s+📆\s*학습 기록[^\n]*\n[\s\S]*?(?=\n---\n|\n##\s|$)/,
    "",
  );
}

async function addCreatedFrontmatter(repositoryRoot, sourceRoot, dates) {
  const noteDirectory = path.join(repositoryRoot, sourceRoot, "note");
  if (!existsSync(noteDirectory)) return;
  const entries = await readdir(noteDirectory, { withFileTypes: true });

  for (const entry of entries) {
    if (!entry.isFile() || !entry.name.endsWith(".md")) continue;
    const notePath = path.join(noteDirectory, entry.name);
    const content = await readFile(notePath, "utf8");
    if (/^---\r?\n[\s\S]*?^created:\s*/m.test(content)) continue;
    const slug = entry.name.slice(0, -3);
    const created = dates.get(slug);
    if (!created) continue;
    await writeFile(notePath, `---\ncreated: ${created}\n---\n\n${content.trimStart()}`);
  }
}

async function discoverTopicRoots(repositoryRoot) {
  const roots = [];

  async function walk(relativeDirectory) {
    const absoluteDirectory = path.join(repositoryRoot, relativeDirectory);
    const entries = await readdir(absoluteDirectory, { withFileTypes: true });
    const directoryNames = new Set(
      entries.filter((entry) => entry.isDirectory()).map((entry) => entry.name),
    );
    const hasReadme = entries.some(
      (entry) => entry.isFile() && entry.name === "README.md",
    );
    const readmeContent = hasReadme
      ? await readFile(path.join(absoluteDirectory, "README.md"), "utf8")
      : "";
    const hasTopicIndex =
      readmeContent.includes(INDEX_START) ||
      (readmeContent.includes("## Notes") &&
        readmeContent.includes("## Theory"));

    if (
      hasReadme &&
      (directoryNames.has("notes") ||
        directoryNames.has("theory") ||
        hasTopicIndex)
    ) {
      roots.push(relativeDirectory);
      return;
    }

    for (const entry of entries) {
      if (!entry.isDirectory() || entry.name === ".git") continue;
      await walk(path.posix.join(relativeDirectory, entry.name));
    }
  }

  await walk("");
  return roots.sort((left, right) => left.localeCompare(right));
}

async function reconcileTopicReadme(repositoryRoot, topicRoot) {
  const readmePath = path.join(repositoryRoot, topicRoot, "README.md");
  const original = existsSync(readmePath)
    ? await readFile(readmePath, "utf8")
    : `# ${path.posix.basename(topicRoot)}\n`;
  const existing = removeLegacyTopicIndexes(original);
  const sourceDirectory = path.join(repositoryRoot, topicRoot, "notes");
  const theoryDirectory = path.join(repositoryRoot, topicRoot, "theory");
  const sources = existsSync(sourceDirectory)
    ? (await readdir(sourceDirectory, { withFileTypes: true }))
        .filter((entry) => entry.isDirectory())
        .map((entry) => entry.name)
        .sort((left, right) => left.localeCompare(right))
    : [];
  const theories = existsSync(theoryDirectory)
    ? (await readdir(theoryDirectory, { withFileTypes: true }))
        .filter(
          (entry) =>
            entry.isFile() &&
            entry.name.endsWith(".md") &&
            entry.name.toLowerCase() !== "readme.md",
        )
        .map((entry) => entry.name)
        .sort((left, right) => left.localeCompare(right))
    : [];
  const block = [
    INDEX_START,
    "## Notes",
    ...(sources.length
      ? sources.map(
          (source) =>
            `- [${source}](${encodeMarkdownPath(`notes/${source}/`)})`,
        )
      : ["", "아직 등록된 note가 없습니다."]),
    "",
    "## Theory",
    ...(theories.length
      ? theories.map(
          (theory) =>
            `- [${theory.replace(/\.md$/i, "")}](${encodeMarkdownPath(`theory/${theory}`)})`,
        )
      : ["", "아직 등록된 theory가 없습니다."]),
    INDEX_END,
  ].join("\n");
  const markerPattern = new RegExp(
    `${escapeRegExp(INDEX_START)}[\\s\\S]*?${escapeRegExp(INDEX_END)}`,
  );
  const next = markerPattern.test(existing)
    ? `${existing.replace(markerPattern, block).trimEnd()}\n`
    : `${existing.trimEnd()}\n\n${block}\n`;
  if (next !== original) await writeFile(readmePath, next);
}

function removeLegacyTopicIndexes(content) {
  const markerIndex = content.indexOf(INDEX_START);
  const prefix = markerIndex === -1 ? content : content.slice(0, markerIndex);
  const suffix = markerIndex === -1 ? "" : content.slice(markerIndex);
  const cleanedPrefix = prefix.replace(
    /(?:\n---\n)?\n## (?:Theory|Notes)\n\n\| (?:문서|자료) \| 링크 \|\n\| --- \| --- \|\n(?:\|[^\n]*\|\n?)*/g,
    "",
  );
  return `${cleanedPrefix.trimEnd()}${suffix ? `\n\n${suffix.trimStart()}` : "\n"}`;
}

function stripControlCharacters(value) {
  return value.replace(/[\u0000-\u001f\u007f]/g, "");
}

function encodeMarkdownPath(value) {
  return value
    .split("/")
    .map((segment) =>
      encodeURIComponent(segment).replace(/\(/g, "%28").replace(/\)/g, "%29"),
    )
    .join("/");
}

function escapeRegExp(value) {
  return value.replace(/[.*+?^${}()|[\]\\]/g, "\\$&");
}

async function main() {
  const dryRun = process.argv.includes("--dry-run");
  const result = await migrateRepository(process.cwd(), { dryRun });
  console.log(
    `${dryRun ? "Planned" : "Migrated"} ${result.sourceCount} source(s) with ${result.moves.length} move(s).`,
  );
  for (const move of result.moves) console.log(`${move.from} -> ${move.to}`);
}

const isMain =
  process.argv[1] &&
  path.resolve(process.argv[1]) === path.resolve(fileURLToPath(import.meta.url));

if (isMain) {
  main().catch((error) => {
    console.error(error instanceof Error ? error.message : error);
    process.exitCode = 1;
  });
}
