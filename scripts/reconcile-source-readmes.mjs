import { existsSync } from "node:fs";
import {
  readFile,
  readdir,
  writeFile,
} from "node:fs/promises";
import path from "node:path";
import { fileURLToPath } from "node:url";
import { parseMarkdown } from "./markdown.mjs";

const START_MARKER = "<!-- til-studio:learning-log:start -->";
const END_MARKER = "<!-- til-studio:learning-log:end -->";

export function findSourceRoots(changedPaths) {
  const roots = new Set();

  for (const changedPath of changedPaths) {
    const segments = changedPath.replaceAll("\\", "/").split("/");
    const notesIndex = segments.indexOf("notes");
    if (notesIndex < 2 || !segments[notesIndex + 1]) continue;
    roots.add(segments.slice(0, notesIndex + 2).join("/"));
  }

  return [...roots].sort((left, right) => left.localeCompare(right));
}

async function existingText(filename) {
  try {
    return await readFile(filename, "utf8");
  } catch (error) {
    if (error.code === "ENOENT") return "";
    throw error;
  }
}

async function directories(directory) {
  if (!existsSync(directory)) return [];
  const entries = await readdir(directory, { withFileTypes: true });
  return entries.filter((entry) => entry.isDirectory() && !entry.name.startsWith("."))
    .map((entry) => entry.name).sort();
}

async function planSourceReadme(root, source) {
  const dir = path.join(root, source);
  const notes = await readNotes(path.join(dir, "note"));
  const slugs = await readSourceSlugs(path.join(dir, "src"));
  const readme = source + "/README.md";
  const current = await existingText(path.join(root, readme));
  const existing = current.trim() ? current : buildMinimalReadme(path.posix.basename(source));
  const content = upsertManagedBlock(existing, buildManagedBlock(notes, slugs), "learning-log", readme);
  return { path: readme, current, content, articleCount: notes.length, hasPractice: slugs.length > 0 };
}

export async function reconcileSourceReadme(root, source) {
  if (!existsSync(path.join(root, source))) return false;
  const plan = await planSourceReadme(root, source);
  if (plan.current === plan.content) return false;
  await writeFile(path.join(root, plan.path), plan.content);
  return true;
}

const readmeName = /^readme(?:[._-].*)?\.md$/i;

function isArticleFile(entry) {
  return entry.isFile() && entry.name.endsWith(".md") && !readmeName.test(entry.name);
}

async function readNotes(noteDirectory) {
  if (!existsSync(noteDirectory)) return [];
  const entries = await readdir(noteDirectory, { withFileTypes: true });
  const notes = [];

  for (const entry of entries) {
    if (!isArticleFile(entry)) continue;
    const slug = entry.name.slice(0, -3);
    const content = await readFile(path.join(noteDirectory, entry.name), "utf8");
    notes.push({
      slug,
      title: parseMarkdown(content).title || readableSlug(slug),
      created: frontmatterValue(content, "created").match(/^["']?(\d{4}-\d{2}-\d{2})["']?$/)?.[1] ?? "",
      srcSlugs: frontmatterSourceSlugs(content),
    });
  }

  return notes.sort(
    (left, right) =>
      compareText(left.created, right.created) || compareText(left.slug, right.slug),
  );
}

function compareText(left, right) {
  return left < right ? -1 : left > right ? 1 : 0;
}

async function containsFile(directory) {
  for (const entry of await readdir(directory, { withFileTypes: true })) {
    if (entry.name === ".gitkeep") continue;
    if (entry.isFile() || (entry.isDirectory() && await containsFile(path.join(directory, entry.name)))) return true;
  }
  return false;
}

async function readSourceSlugs(srcDirectory) {
  const slugs = [];
  for (const slug of await directories(srcDirectory)) {
    if (await containsFile(path.join(srcDirectory, slug))) slugs.push(slug);
  }
  return slugs;
}

function frontmatterValue(content, key) {
  const frontmatter = content.match(/^---\r?\n([\s\S]*?)\r?\n---/)?.[1];
  if (!frontmatter) return "";
  const line = frontmatter
    .split(/\r?\n/)
    .find((candidate) => candidate.startsWith(`${key}:`));
  return line?.slice(key.length + 1).trim() ?? "";
}

function buildManagedBlock(notes, srcSlugs) {
  const sourceSet = new Set(srcSlugs);
  const linkedSourceSlugs = new Set();
  const rows = notes.map((note) => {
    const explicitSlugs = note.srcSlugs.filter((slug) => sourceSet.has(slug));
    const linkedSlugs = explicitSlugs.length
      ? explicitSlugs
      : sourceSet.has(note.slug)
        ? [note.slug]
        : [];
    for (const slug of linkedSlugs) linkedSourceSlugs.add(slug);
    const src = linkedSlugs.length
      ? linkedSlugs.map((slug) => tableLink(slug, `./src/${slug}/`)).join(", ")
      : "-";
    const noteFilename = note.slug + ".md";
    const noteLink = tableLink(noteFilename, "./note/" + noteFilename);
    return `| ${note.created || "-"} | ${tableText(note.title)} | ${src} | ${noteLink} |`;
  });

  for (const slug of srcSlugs.filter((slug) => !linkedSourceSlugs.has(slug))) {
    rows.push(`| - | ${tableText(readableSlug(slug))} | ${tableLink(slug, `./src/${slug}/`)} | - |`);
  }

  if (!rows.length) {
    rows.push("| - | 아직 작성된 학습 기록이 없습니다. | - | - |");
  }

  return `${START_MARKER}
## 학습 기록

| 날짜 | 주제 | src | note |
| --- | --- | --- | --- |
${rows.join("\n")}
${END_MARKER}`;
}

function frontmatterSourceSlugs(content) {
  const frontmatter = content.match(/^---\r?\n([\s\S]*?)\r?\n---/)?.[1];
  if (!frontmatter) return [];

  const lines = frontmatter.split(/\r?\n/);
  const slugs = [];

  for (let index = 0; index < lines.length; index += 1) {
    const inline = lines[index].match(/^src:\s*(.+?)\s*$/);
    if (inline) {
      slugs.push(...inlineSourceSlugs(inline[1]));
      continue;
    }

    if (!/^src:\s*$/.test(lines[index])) continue;
    for (let cursor = index + 1; cursor < lines.length; cursor += 1) {
      const item = lines[cursor].match(/^\s*-\s*(.+?)\s*$/);
      if (!item) break;
      slugs.push(cleanSourceSlug(item[1]));
      index = cursor;
    }
  }

  return [...new Set(slugs.filter(Boolean))];
}

function inlineSourceSlugs(value) {
  const trimmed = value.trim();
  if (!trimmed) return [];
  if (trimmed.startsWith("[") && trimmed.endsWith("]")) {
    return trimmed
      .slice(1, -1)
      .split(",")
      .map(cleanSourceSlug)
      .filter(Boolean);
  }
  return [cleanSourceSlug(trimmed)].filter(Boolean);
}

function cleanSourceSlug(value) {
  return value.trim().replace(/^["']|["']$/g, "");
}

function upsertManagedBlock(existing, block, kind, readme) {
  const startMarker = `<!-- til-studio:${kind}:start -->`;
  const endMarker = `<!-- til-studio:${kind}:end -->`;
  const start = existing.indexOf(startMarker);
  const end = existing.indexOf(endMarker);
  if (start === -1 && end === -1) {
    const separator = !existing || /\n\r?\n$/.test(existing) ? "" : existing.endsWith("\n") ? "\n" : "\n\n";
    return existing + separator + block + "\n";
  }
  if (start < 0 || end < start || start !== existing.lastIndexOf(startMarker) || end !== existing.lastIndexOf(endMarker)) {
    throw new Error(`${readme}: managed ${kind} markers are malformed`);
  }
  return existing.slice(0, start) + block + existing.slice(end + endMarker.length);
}

function buildMinimalReadme(sourceName) {
  return `# ${sourceName}

[상위 topic으로 이동](../../README.md)

${sourceGuidance(sourceName)}
`;
}

function sourceGuidance(sourceName) {
  return `## 디렉토리 구조

\`\`\`text
${sourceName}/
├── README.md
├── note/    # 학습 기록 Markdown
└── src/     # 실행 코드와 실습 파일
\`\`\`

## 작성 원칙

- 학습 기록은 \`note/<slug>.md\`에 작성한다.
- 관련 코드는 \`src/<slug>/\`에 둔다.
- note와 src는 기본적으로 slug가 같으면 연결한다.
- note slug와 src 폴더명이 다르면 note frontmatter의 \`src\` 목록으로 연결한다.
- 예: \`src: [ch1, ch2]\`는 해당 note를 \`src/ch1/\`, \`src/ch2/\`와 연결한다.
- 아래 학습 기록 marker 사이 내용은 자동 관리되므로 직접 수정하지 않는다.`;
}

function escapeTable(value) {
  return value.replaceAll("|", "\\|").replace(/\r?\n/g, " ");
}

function tableText(value) {
  return escapeTable(value.replaceAll("\\", "\\\\"));
}

function tableLink(label, destination) {
  return escapeTable(link(label, destination));
}

function escapeLinkLabel(value) {
  return value.replaceAll("\\", "\\\\").replaceAll("[", "\\[").replaceAll("]", "\\]");
}

function readableSlug(slug) {
  return slug.replaceAll("-", " ");
}

function encodeMarkdownPath(value) {
  return value
    .split("/")
    .map((segment) =>
      encodeURIComponent(segment).replace(/\(/g, "%28").replace(/\)/g, "%29"),
    )
    .join("/");
}

const infrastructure = new Set(["docs", "node_modules", "scripts", "templates", "tests"]);
const studyAreas = new Set(["cs", "languages", "projects", "software-engineering"]);

function link(label, destination) {
  return `[${escapeLinkLabel(label)}](${encodeMarkdownPath(destination)})`;
}

function managedList(kind, lines) {
  return [`<!-- til-studio:${kind}:start -->`, ...lines, `<!-- til-studio:${kind}:end -->`].join("\n");
}

async function planTopic(root, topic, plans) {
  const topicDir = path.join(root, topic);
  const sourceNames = await directories(path.join(topicDir, "notes"));
  let articleCount = 0;
  let hasPractice = false;
  for (const sourceName of sourceNames) {
    const source = await planSourceReadme(root, `${topic}/notes/${sourceName}`);
    plans.push(source);
    articleCount += source.articleCount;
    hasPractice ||= source.hasPractice;
  }

  const theoryDir = path.join(topicDir, "theory");
  const articles = existsSync(theoryDir)
    ? (await readdir(theoryDir, { withFileTypes: true })).filter(isArticleFile).map((entry) => entry.name).sort()
    : [];
  const lines = ["## Notes"];
  if (sourceNames.length) {
    for (const name of sourceNames) lines.push("- " + link(name, `notes/${name}/`));
  } else lines.push("", "아직 등록된 note가 없습니다.");
  lines.push("", "## Theory");
  if (articles.length) {
    for (const name of articles) {
      const title = parseMarkdown(await readFile(path.join(theoryDir, name), "utf8")).title;
      lines.push("- " + link(title || name.slice(0, -3), "theory/" + name));
    }
  } else lines.push("", "아직 등록된 theory가 없습니다.");

  const readme = topic + "/README.md";
  const current = await existingText(path.join(root, readme));
  const base = current || `[상위 README로 이동](../README.md)\n\n# ${path.posix.basename(topic)}\n`;
  plans.push({ path: readme, current, content: upsertManagedBlock(base, managedList("index", lines), "index", readme) });
  return { articleCount: articleCount + articles.length, hasPractice };
}

// Only migrate the old links-only table. A customized section is human content.
function replaceLegacyLanguagesList(current, block) {
  if (current.includes("<!-- til-studio:children:")) return current;
  return current.replace(
    /^## 언어 목록\r?\n\r?\n\| 언어 \| 링크 \|\r?\n\| --- \| --- \|(?:\r?\n\| [^|\r\n]+ \| \[바로가기\]\(\.\/[^/)]+\/\) \|)+(?=\r?\n\r?\n(?:---|## )|\r?\n?$)/m,
    () => block,
  );
}

async function planChildren(root, dir, rows) {
  const readme = dir ? dir + "/README.md" : "README.md";
  const current = await existingText(path.join(root, readme));
  let base = current || (dir ? `[상위 README로 이동](../README.md)\n\n# ${dir}\n` : "# TIL\n");
  const block = managedList("children", ["## 하위 항목", "", ...(rows.length ? rows : ["아직 등록된 하위 항목이 없습니다."])]);
  if (dir === "languages") base = replaceLegacyLanguagesList(base, block);
  return { path: readme, current, content: upsertManagedBlock(base, block, "children", readme) };
}

// Plan all changes before writing so a malformed marker cannot partially update the indexes.
export async function reconcileRepository(root, { check = false } = {}) {
  const plans = [];
  const areas = (await directories(root)).filter((name) => !infrastructure.has(name));
  for (const area of areas.filter((name) => studyAreas.has(name))) {
    const dir = path.join(root, area);
    const topics = await directories(dir);
    const rows = [];
    for (const name of topics) {
      const topic = area + "/" + name;
      if (area !== "cs" && area !== "languages"
          && !existsSync(path.join(root, topic, "notes")) && !existsSync(path.join(root, topic, "theory"))
          && !(await existingText(path.join(root, topic, "README.md"))).includes("<!-- til-studio:index:")) {
        continue;
      }
      const { articleCount, hasPractice } = await planTopic(root, topic, plans);
      const status = articleCount ? `글 ${articleCount}편` : hasPractice ? "실습 코드" : "작성 예정";
      rows.push(`- ${link(name, name + "/")} — ${status}`);
    }
    const previous = await existingText(path.join(dir, "README.md"));
    if (rows.length || previous.includes("<!-- til-studio:children:")) {
      plans.push(await planChildren(root, area, rows));
    }
  }
  plans.push(await planChildren(root, "", areas.map((area) => "- " + link(area, area + "/"))));
  const changes = plans.filter(({ current, content }) => current !== content);
  if (!check) {
    for (const change of changes) await writeFile(path.join(root, change.path), change.content);
  }
  return changes.map((change) => change.path);
}

async function main() {
  const args = process.argv.slice(2);
  const check = args.includes("--check");
  const changedFile = args.indexOf("--changed-paths-file");
  if (changedFile >= 0 && args[changedFile + 1]) {
    // Legacy callers may provide NUL- or newline-delimited Git paths. All indexes
    // depend on the current tree, including paths removed or renamed in a push.
    await readFile(args[changedFile + 1]);
  } else if (!args.includes("--all") && !check) {
    throw new Error("usage: node scripts/reconcile-source-readmes.mjs --all [--check]");
  }
  const changes = await reconcileRepository(process.cwd(), { check });
  for (const file of changes) console.log(file);
  console.log(`${check ? "Out of date" : "Updated"}: ${changes.length} README(s).`);
  if (check && changes.length) process.exitCode = 1;
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
