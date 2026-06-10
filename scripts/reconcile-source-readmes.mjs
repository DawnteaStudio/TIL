import { existsSync } from "node:fs";
import {
  mkdir,
  readFile,
  readdir,
  stat,
  writeFile,
} from "node:fs/promises";
import path from "node:path";
import { fileURLToPath } from "node:url";

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

export async function reconcileSourceReadme(repositoryRoot, sourceRoot) {
  const absoluteSource = path.join(repositoryRoot, sourceRoot);
  if (!existsSync(absoluteSource)) return false;

  const notes = await readNotes(path.join(absoluteSource, "note"));
  const srcSlugs = await readSourceSlugs(path.join(absoluteSource, "src"));
  const readmePath = path.join(absoluteSource, "README.md");
  const current = existsSync(readmePath)
    ? await readFile(readmePath, "utf8")
    : "";
  const existing = current.trim()
    ? current
    : buildMinimalReadme(path.posix.basename(sourceRoot));
  const guided = ensureSourceGuidance(
    existing,
    path.posix.basename(sourceRoot),
  );
  const next = upsertManagedBlock(guided, buildManagedBlock(notes, srcSlugs));

  if (next === existing) return false;
  await mkdir(absoluteSource, { recursive: true });
  await writeFile(readmePath, next);
  return true;
}

async function readNotes(noteDirectory) {
  if (!existsSync(noteDirectory)) return [];
  const entries = await readdir(noteDirectory, { withFileTypes: true });
  const notes = [];

  for (const entry of entries) {
    if (!entry.isFile() || !entry.name.endsWith(".md")) continue;
    const slug = entry.name.slice(0, -3);
    const content = await readFile(path.join(noteDirectory, entry.name), "utf8");
    notes.push({
      slug,
      title: firstHeading(content) || slug,
      created: frontmatterValue(content, "created") || "-",
    });
  }

  return notes.sort(
    (left, right) =>
      left.created.localeCompare(right.created) ||
      left.slug.localeCompare(right.slug),
  );
}

async function readSourceSlugs(srcDirectory) {
  if (!existsSync(srcDirectory)) return [];
  const entries = await readdir(srcDirectory, { withFileTypes: true });
  return entries
    .filter((entry) => entry.isDirectory())
    .map((entry) => entry.name)
    .sort((left, right) => left.localeCompare(right));
}

function firstHeading(content) {
  const body = content.replace(/^---\r?\n[\s\S]*?\r?\n---\r?\n?/, "");
  const heading = body
    .split(/\r?\n/)
    .map((line) => line.match(/^#{1,6}[ \t]+(.+)$/)?.[1])
    .find(Boolean);
  return heading
    ?.replace(/\[([^\]]+)\]\([^)]+\)/g, "$1")
    .replace(/[*_`]/g, "")
    .trim();
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
  const noteSlugs = new Set(notes.map((note) => note.slug));
  const rows = notes.map((note) => {
    const src = srcSlugs.includes(note.slug)
      ? `[${escapeLinkLabel(note.slug)}](${encodeMarkdownPath(`./src/${note.slug}/`)})`
      : "-";
    const noteFilename = `${note.slug}.md`;
    return `| ${note.created} | ${escapeTable(note.title)} | ${src} | [${escapeLinkLabel(noteFilename)}](${encodeMarkdownPath(`./note/${noteFilename}`)}) |`;
  });

  for (const slug of srcSlugs.filter((slug) => !noteSlugs.has(slug))) {
    rows.push(
      `| - | ${escapeTable(readableSlug(slug))} | [${escapeLinkLabel(slug)}](${encodeMarkdownPath(`./src/${slug}/`)}) | - |`,
    );
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

function upsertManagedBlock(existing, managedBlock) {
  const startCount = count(existing, START_MARKER);
  const endCount = count(existing, END_MARKER);
  if (startCount !== endCount || startCount > 1) {
    throw new Error("managed learning-log markers are malformed");
  }

  if (startCount === 0) {
    return `${existing.trimEnd()}\n\n${managedBlock}\n`;
  }

  const start = existing.indexOf(START_MARKER);
  const end = existing.indexOf(END_MARKER) + END_MARKER.length;
  return `${existing.slice(0, start)}${managedBlock}${existing.slice(end)}`;
}

function buildMinimalReadme(sourceName) {
  return `# ${sourceName}

[상위 topic으로 이동](../../README.md)

${sourceGuidance(sourceName)}
`;
}

function ensureSourceGuidance(content, sourceName) {
  if (
    content.includes("## 디렉토리 구조") &&
    content.includes("## 작성 원칙")
  ) {
    return content;
  }

  const guidance = sourceGuidance(sourceName);
  const markerIndex = content.indexOf(START_MARKER);
  if (markerIndex === -1) {
    return `${content.trimEnd()}\n\n${guidance}\n`;
  }

  return `${content.slice(0, markerIndex).trimEnd()}\n\n${guidance}\n\n${content.slice(markerIndex)}`;
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
- note와 src는 대소문자를 포함해 slug가 정확히 같을 때만 연결한다.
- 아래 학습 기록 marker 사이 내용은 자동 관리되므로 직접 수정하지 않는다.`;
}

function escapeTable(value) {
  return value.replaceAll("|", "\\|").replace(/\r?\n/g, " ");
}

function escapeLinkLabel(value) {
  return escapeTable(value).replaceAll("[", "\\[").replaceAll("]", "\\]");
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

function count(value, needle) {
  return value.split(needle).length - 1;
}

async function readChangedPathsFile(filePath) {
  const content = await readFile(filePath, "utf8");
  return content.split(/\r?\n/).filter(Boolean);
}

async function main() {
  const args = process.argv.slice(2);
  const fileIndex = args.indexOf("--changed-paths-file");
  if (fileIndex === -1 || !args[fileIndex + 1]) {
    throw new Error("usage: node scripts/reconcile-source-readmes.mjs --changed-paths-file <path>");
  }

  const repositoryRoot = process.cwd();
  const changedPaths = await readChangedPathsFile(args[fileIndex + 1]);
  const roots = findSourceRoots(changedPaths);
  let changed = 0;

  for (const sourceRoot of roots) {
    if (await reconcileSourceReadme(repositoryRoot, sourceRoot)) changed += 1;
  }

  console.log(`Reconciled ${roots.length} source(s); updated ${changed} README file(s).`);
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
