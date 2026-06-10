import assert from "node:assert/strict";
import { mkdtemp, mkdir, readFile, writeFile } from "node:fs/promises";
import os from "node:os";
import path from "node:path";
import test from "node:test";
import {
  migrateRepository,
  planSourceMigration,
} from "../scripts/migrate-source-layout.mjs";

async function fixture() {
  return mkdtemp(path.join(os.tmpdir(), "til-source-migration-"));
}

test("planSourceMigration normalizes legacy source paths", async () => {
  const root = await fixture();
  const sourceRoot = "languages/python/notes/jump_to_python";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(path.join(absoluteSource, "\bcode", "ch2"), { recursive: true });
  await writeFile(path.join(absoluteSource, "\bcode", "ch2", "quiz.py"), "print('ok')\n");
  await writeFile(path.join(absoluteSource, "\bREADME.md"), "# 점프 투 파이썬\n");
  await writeFile(path.join(absoluteSource, "chapter.md"), "# Chapter\n");

  const plan = await planSourceMigration(root, sourceRoot);

  assert.deepEqual(
    new Set(plan.moves.map((move) => JSON.stringify(move))),
    new Set(
      [
        {
          from: `${sourceRoot}/\bREADME.md`,
          to: `${sourceRoot}/README.md`,
        },
        {
          from: `${sourceRoot}/\bcode`,
          to: `${sourceRoot}/src`,
        },
        {
          from: `${sourceRoot}/chapter.md`,
          to: `${sourceRoot}/note/chapter.md`,
        },
      ].map((move) => JSON.stringify(move)),
    ),
  );
});

test("migrateRepository moves content and preserves README learning dates", async () => {
  const root = await fixture();
  const sourceRoot = "languages/c/notes/hongongC";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(path.join(absoluteSource, "code", "ch2"), { recursive: true });
  await mkdir(path.join(absoluteSource, "note"), { recursive: true });
  await writeFile(path.join(absoluteSource, "code", "ch2", "main.c"), "int main() {}\n");
  await writeFile(path.join(absoluteSource, "note", "ch2.md"), "# 상수와 데이터 출력\n");
  await writeFile(
    path.join(absoluteSource, "README.md"),
    [
      "# 혼자 공부하는 C",
      "",
      "## 📆 학습 기록 (Learning Log)",
      "| 날짜 | 학습 내용 | 소스 코드 | 노트 정리 |",
      "| --- | --- | --- | --- |",
      "| 2023-07-30 | Chapter 02 | [ch2](./code/ch2/) | [ch2](./note/ch2.md) |",
      "",
      "## 📌 참고 자료 (References)",
      "- 책",
      "",
    ].join("\n"),
  );

  const result = await migrateRepository(root);

  assert.equal(result.sourceCount, 1);
  const note = await readFile(path.join(absoluteSource, "note", "ch2.md"), "utf8");
  const readme = await readFile(path.join(absoluteSource, "README.md"), "utf8");
  assert.match(note, /^---\ncreated: 2023-07-30\n---/);
  assert.match(readme, /\[src\]\(\.\/src\/ch2\/\)/);
  assert.doesNotMatch(readme, /\.\/code\//);
  assert.equal(readme.match(/## 학습 기록/g)?.length, 1);
});

test("migrateRepository encodes parentheses in topic source links", async () => {
  const root = await fixture();
  const topicRoot = "cs/networks";
  const sourceName = "TCP_IP(윤성우)";
  await mkdir(path.join(root, topicRoot, "notes", sourceName), {
    recursive: true,
  });
  await writeFile(path.join(root, topicRoot, "README.md"), "# Networks\n");

  await migrateRepository(root);

  const readme = await readFile(path.join(root, topicRoot, "README.md"), "utf8");
  assert.match(
    readme,
    /notes\/TCP_IP%28%EC%9C%A4%EC%84%B1%EC%9A%B0%29\//,
  );
});

test("migrateRepository removes legacy topic indexes before writing the managed index", async () => {
  const root = await fixture();
  const topicRoot = "cs/algorithms";
  await mkdir(path.join(root, topicRoot, "notes", "APSS"), {
    recursive: true,
  });
  await mkdir(path.join(root, topicRoot, "theory"), {
    recursive: true,
  });
  await writeFile(
    path.join(root, topicRoot, "theory", "kmp.md"),
    "# KMP\n",
  );
  await writeFile(
    path.join(root, topicRoot, "README.md"),
    [
      "# Algorithms",
      "",
      "## 구조",
      "",
      "설명",
      "",
      "---",
      "",
      "## Theory",
      "",
      "| 문서 | 링크 |",
      "| --- | --- |",
      "| KMP | [바로가기](./theory/kmp.md) |",
      "",
      "---",
      "",
      "## Notes",
      "",
      "| 자료 | 링크 |",
      "| --- | --- |",
      "| APSS | [바로가기](./notes/APSS/) |",
      "",
      "<!-- til-studio:index:start -->",
      "## Notes",
      "- [APSS](notes/APSS/)",
      "",
      "## Theory",
      "- [kmp](theory/kmp.md)",
      "<!-- til-studio:index:end -->",
      "",
    ].join("\n"),
  );

  await migrateRepository(root);

  const readme = await readFile(path.join(root, topicRoot, "README.md"), "utf8");
  assert.equal(readme.match(/^## Notes$/gm)?.length, 1);
  assert.equal(readme.match(/^## Theory$/gm)?.length, 1);
  assert.doesNotMatch(readme, /\| 자료 \| 링크 \|/);
  assert.doesNotMatch(readme, /\| 문서 \| 링크 \|/);
  assert.match(readme, /- \[APSS\]\(notes\/APSS\/\)/);
  assert.match(readme, /- \[kmp\]\(theory\/kmp\.md\)/);
});

test("migrateRepository normalizes a topic even when it has no source directories", async () => {
  const root = await fixture();
  const topicRoot = "cs/security";
  await mkdir(path.join(root, topicRoot), {
    recursive: true,
  });
  await writeFile(
    path.join(root, topicRoot, "README.md"),
    [
      "# Security",
      "",
      "## Theory",
      "",
      "| 문서 | 링크 |",
      "| --- | --- |",
      "| 아직 기록된 문서가 없습니다. | - |",
      "",
      "## Notes",
      "",
      "| 자료 | 링크 |",
      "| --- | --- |",
      "| 아직 기록된 자료가 없습니다. | - |",
      "",
    ].join("\n"),
  );

  await migrateRepository(root);

  const readme = await readFile(path.join(root, topicRoot, "README.md"), "utf8");
  assert.equal(readme.match(/^## Notes$/gm)?.length, 1);
  assert.equal(readme.match(/^## Theory$/gm)?.length, 1);
  assert.match(readme, /<!-- til-studio:index:start -->/);
  assert.doesNotMatch(readme, /\| 자료 \| 링크 \|/);
});

test("planSourceMigration rejects destination collisions", async () => {
  const root = await fixture();
  const sourceRoot = "cs/networks/notes/tcp";
  const absoluteSource = path.join(root, sourceRoot);
  await mkdir(path.join(absoluteSource, "code"), { recursive: true });
  await mkdir(path.join(absoluteSource, "src"), { recursive: true });

  await assert.rejects(
    planSourceMigration(root, sourceRoot),
    /migration destination already exists/,
  );
});
