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
  assert.match(
    readme,
    /\| 2026-06-10 \| 변수와 자료형 \| \[src\]\(\.\/src\/ch2\/\) \| \[note\]\(\.\/note\/ch2\.md\) \|/,
  );
  assert.match(
    readme,
    /\| 2026-06-11 \| 연산자 \| - \| \[note\]\(\.\/note\/ch3\.md\) \|/,
  );
  assert.match(readme, /- \[ \] `Ch3` \(\[src\]\(\.\/src\/Ch3\/\)\)/);
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
  assert.match(readme, /- \[ \] `socket` \(\[src\]\(\.\/src\/socket\/\)\)/);
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
