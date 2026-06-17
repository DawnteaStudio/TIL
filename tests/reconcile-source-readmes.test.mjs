import assert from "node:assert/strict";
import { mkdtemp, mkdir, readFile, writeFile } from "node:fs/promises";
import os from "node:os";
import path from "node:path";
import test from "node:test";
import {
  findSourceRoots,
  reconcileSourceReadme,
} from "../scripts/reconcile-source-readmes.mjs";

async function fixture() {
  return mkdtemp(path.join(os.tmpdir(), "til-source-readme-"));
}

test("findSourceRoots returns only changed source roots", () => {
  assert.deepEqual(
    findSourceRoots([
      "languages/c/notes/hongongC/note/ch2.md",
      "languages/c/notes/hongongC/src/ch2/example.c",
      "cs/algorithms/theory/kmp.md",
      "cs/software-engineering/notes/etc/README.md",
    ]),
    [
      "cs/software-engineering/notes/etc",
      "languages/c/notes/hongongC",
    ],
  );
});

test("reconcileSourceReadme pairs exact note and src slugs", async () => {
  const root = await fixture();
  const sourceRoot = "languages/c/notes/hongongC";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(path.join(absoluteSource, "note"), { recursive: true });
  await mkdir(path.join(absoluteSource, "src", "ch2"), { recursive: true });
  await mkdir(path.join(absoluteSource, "src", "Ch3"), { recursive: true });
  await writeFile(
    path.join(absoluteSource, "note", "ch2.md"),
    "---\ncreated: 2026-06-10\n---\n\n# 변수와 자료형\n",
  );
  await writeFile(
    path.join(absoluteSource, "note", "ch3.md"),
    "---\ncreated: 2026-06-11\n---\n\n# 연산자\n",
  );
  await writeFile(path.join(absoluteSource, "src", "ch2", "main.c"), "int main() {}\n");
  await writeFile(path.join(absoluteSource, "src", "Ch3", "main.c"), "int main() {}\n");
  await writeFile(
    path.join(absoluteSource, "README.md"),
    "# 혼자 공부하는 C\n\n직접 작성한 소개다.\n",
  );

  await reconcileSourceReadme(root, sourceRoot);

  const readme = await readFile(path.join(absoluteSource, "README.md"), "utf8");
  assert.match(readme, /직접 작성한 소개다\./);
  assert.doesNotMatch(readme, /## 디렉토리 구조/);
  assert.doesNotMatch(readme, /## 작성 원칙/);
  assert.match(
    readme,
    /\| 2026-06-10 \| 변수와 자료형 \| \[ch2\]\(\.\/src\/ch2\/\) \| \[ch2\.md\]\(\.\/note\/ch2\.md\) \|/,
  );
  assert.match(
    readme,
    /\| 2026-06-11 \| 연산자 \| - \| \[ch3\.md\]\(\.\/note\/ch3\.md\) \|/,
  );
  assert.match(
    readme,
    /\| - \| Ch3 \| \[Ch3\]\(\.\/src\/Ch3\/\) \| - \|/,
  );
  assert.doesNotMatch(readme, /note 작성 대기/);
});

test("reconcileSourceReadme links notes to explicit source frontmatter", async () => {
  const root = await fixture();
  const sourceRoot = "languages/java/notes/java-basic";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(path.join(absoluteSource, "note"), { recursive: true });
  await mkdir(path.join(absoluteSource, "src", "ch1"), { recursive: true });
  await mkdir(path.join(absoluteSource, "src", "ch2"), { recursive: true });
  await mkdir(path.join(absoluteSource, "src", "ch3"), { recursive: true });
  await writeFile(
    path.join(absoluteSource, "note", "class-loading.md"),
    "---\ncreated: 2026-06-17\nsrc:\n  - ch1\n  - ch2\n---\n\n# 클래스 로딩\n",
  );
  await writeFile(path.join(absoluteSource, "src", "ch1", "Main.java"), "class Main {}\n");
  await writeFile(path.join(absoluteSource, "src", "ch2", "Main.java"), "class Main {}\n");
  await writeFile(path.join(absoluteSource, "src", "ch3", "Main.java"), "class Main {}\n");

  await reconcileSourceReadme(root, sourceRoot);

  const readme = await readFile(path.join(absoluteSource, "README.md"), "utf8");
  assert.match(
    readme,
    /\| 2026-06-17 \| 클래스 로딩 \| \[ch1\]\(\.\/src\/ch1\/\), \[ch2\]\(\.\/src\/ch2\/\) \| \[class-loading\.md\]\(\.\/note\/class-loading\.md\) \|/,
  );
  assert.match(readme, /\| - \| ch3 \| \[ch3\]\(\.\/src\/ch3\/\) \| - \|/);
  assert.doesNotMatch(readme, /\| - \| ch1 \|/);
  assert.doesNotMatch(readme, /\| - \| ch2 \|/);
});

test("reconcileSourceReadme creates a minimal README for src-first work", async () => {
  const root = await fixture();
  const sourceRoot = "cs/networks/notes/tcp-ip";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(path.join(absoluteSource, "src", "socket"), { recursive: true });
  await writeFile(path.join(absoluteSource, "src", "socket", "server.c"), "int main() {}\n");

  await reconcileSourceReadme(root, sourceRoot);

  const readme = await readFile(path.join(absoluteSource, "README.md"), "utf8");
  assert.match(readme, /^# tcp-ip/m);
  assert.match(readme, /\[상위 topic으로 이동\]\(\.\.\/\.\.\/README\.md\)/);
  assert.match(
    readme,
    /\| - \| socket \| \[socket\]\(\.\/src\/socket\/\) \| - \|/,
  );
  assert.doesNotMatch(readme, /note 작성 대기/);
});

test("reconcileSourceReadme replaces an empty README with source guidance", async () => {
  const root = await fixture();
  const sourceRoot = "cs/networks/notes/tcp";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(absoluteSource, { recursive: true });
  await writeFile(path.join(absoluteSource, "README.md"), "\n");

  await reconcileSourceReadme(root, sourceRoot);

  const readme = await readFile(path.join(absoluteSource, "README.md"), "utf8");
  assert.match(readme, /## 디렉토리 구조/);
  assert.match(readme, /## 작성 원칙/);
});

test("reconcileSourceReadme uses the first heading line when a note has no h1", async () => {
  const root = await fixture();
  const sourceRoot = "languages/c/notes/book";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(path.join(absoluteSource, "note"), { recursive: true });
  await writeFile(
    path.join(absoluteSource, "note", "ch2.md"),
    "---\ncreated: 2026-06-10\n---\n\n[상위로](../README.md)\n\n## C 언어 기본 구조\n",
  );

  await reconcileSourceReadme(root, sourceRoot);

  const readme = await readFile(path.join(absoluteSource, "README.md"), "utf8");
  assert.match(readme, /\| 2026-06-10 \| C 언어 기본 구조 \|/);
});

test("reconcileSourceReadme rejects malformed managed markers", async () => {
  const root = await fixture();
  const sourceRoot = "cs/algorithms/notes/APSS";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(absoluteSource, { recursive: true });
  await writeFile(
    path.join(absoluteSource, "README.md"),
    "# APSS\n\n<!-- til-studio:learning-log:start -->\n",
  );

  await assert.rejects(
    reconcileSourceReadme(root, sourceRoot),
    /managed learning-log markers are malformed/,
  );
});

test("reconcileSourceReadme updates only the learning log in a Studio-formatted README", async () => {
  const root = await fixture();
  const sourceRoot = "languages/java/notes/java-intro";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(path.join(absoluteSource, "note"), { recursive: true });
  await writeFile(
    path.join(absoluteSource, "note", "variables.md"),
    "---\ncreated: 2026-06-11\n---\n\n# 변수와 타입\n",
  );
  await writeFile(
    path.join(absoluteSource, "README.md"),
    studioReadme("java-intro", "| - | 이전 기록 | - | - |"),
  );

  await reconcileSourceReadme(root, sourceRoot);

  const readme = await readFile(path.join(absoluteSource, "README.md"), "utf8");
  assert.equal((readme.match(/## 디렉터리 구조/g) ?? []).length, 1);
  assert.equal((readme.match(/## 디렉토리 구조/g) ?? []).length, 0);
  assert.equal((readme.match(/## 작성 원칙/g) ?? []).length, 1);
  assert.match(
    readme,
    /\| 2026-06-11 \| 변수와 타입 \| - \| \[variables\.md\]\(\.\/note\/variables\.md\) \|/,
  );
});

test("reconcileSourceReadme is a no-op when a Studio learning log is current", async () => {
  const root = await fixture();
  const sourceRoot = "languages/java/notes/java-intro";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(path.join(absoluteSource, "note"), { recursive: true });
  await writeFile(
    path.join(absoluteSource, "note", "variables.md"),
    "---\ncreated: 2026-06-11\n---\n\n# 변수와 타입\n",
  );
  await writeFile(
    path.join(absoluteSource, "README.md"),
    studioReadme(
      "java-intro",
      "| 2026-06-11 | 변수와 타입 | - | [variables.md](./note/variables.md) |",
    ),
  );

  assert.equal(await reconcileSourceReadme(root, sourceRoot), false);
});

function studioReadme(sourceName, learningRow) {
  return `[상위 README로 이동](../../README.md)

# Java Intro

유형: 강의

## 개요

Java 학습 내용을 정리합니다.

## 디렉터리 구조

\`\`\`text

${sourceName}/

├── README.md

├── note/    # 학습 기록 Markdown

└── src/     # note와 같은 slug를 사용하는 실습 코드

\`\`\`

## 작성 원칙

- 같은 학습 단위는 하나의 slug를 사용합니다.

- 학습 기록은 \`note/<slug>.md\`에 작성합니다.

- 관련 실습 코드는 \`src/<slug>/\` 아래에 둡니다.

- note와 src는 어느 한쪽만 먼저 존재해도 됩니다.

- 학습 기록 관리 블록은 자동 생성되므로 직접 수정하지 않습니다.

---

<!-- til-studio:learning-log:start -->
## 학습 기록

| 날짜 | 주제 | src | note |
| --- | --- | --- | --- |
${learningRow}
<!-- til-studio:learning-log:end -->
`;
}
