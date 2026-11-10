import importlib.util
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]

def load(name, file):
    spec = importlib.util.spec_from_file_location(name, ROOT / file)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module

organizer = load("organizer", ".github/workflows/update_baekjoon.py")


class CodingArchiveTest(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)

    def put(self, path, data):
        file = self.root / path
        file.parent.mkdir(parents=True, exist_ok=True)
        file.write_bytes(data)
        return file

    def test_archive_preserves_statement_relative_files_and_unknown_paths(self):
        prefix = "백준/Silver/1234. 두 수/"
        readme = b"[solution](mine.cc) [example](input/data.json)"
        self.put(prefix + "README.md", readme)
        self.put(prefix + "mine.cc", b"solve")
        self.put(prefix + "input/data.json", b"example")
        untouched = self.put("백준/scratch/notes.md", b"manual")
        no_code = self.put("백준/Gold/3000. 빈 문제/README.md", b"not submitted")
        self.put("프로그래머스/3/456. 피자/pizza.py", b"solution")
        organizer.organize(self.root)
        base = self.root / "coding-test/Baekjoon/1000"
        self.assertEqual((base / "1234.cpp").read_bytes(), b"solve")
        self.assertEqual((base / "1234/README.md").read_bytes(), readme)
        self.assertEqual((base / "1234/mine.cc").read_bytes(), b"solve")
        self.assertEqual((base / "1234/input/data.json").read_bytes(), b"example")
        self.assertEqual((self.root / "coding-test/Programmers/3/456.py").read_bytes(), b"solution")
        self.assertEqual(untouched.read_bytes(), b"manual")
        self.assertEqual(no_code.read_bytes(), b"not submitted")
        self.assertFalse((self.root / prefix / "mine.cc").exists())
        self.assertEqual(organizer.organize(self.root), [])

    def test_different_existing_or_competing_destination_keeps_every_source(self):
        a = self.put("백준/Silver/1234. 이름/A.cc", b"one")
        b = self.put("백준/Gold/1234. 기타/B.cpp", b"two")
        with self.assertRaises(ValueError):
            organizer.organize(self.root)
        self.assertEqual(a.read_bytes(), b"one")
        self.assertEqual(b.read_bytes(), b"two")
        b.unlink()
        dest = self.put("coding-test/Baekjoon/1000/1234.cpp", b"existing")
        with self.assertRaises(ValueError):
            organizer.organize(self.root)
        self.assertEqual(dest.read_bytes(), b"existing")
        self.assertEqual(a.read_bytes(), b"one")

    def test_manual_readme_conflict_does_not_remove_input_or_change_target(self):
        source = self.put("프로그래머스/0/12. 테스트/README.md", b"import")
        self.put("프로그래머스/0/12. 테스트/main.py", b"solve")
        manual = self.put("coding-test/Programmers/0/12/README.md", b"edited here")
        with self.assertRaises(ValueError):
            organizer.organize(self.root)
        self.assertEqual(source.read_bytes(), b"import")
        self.assertEqual(manual.read_bytes(), b"edited here")

    def test_staging_includes_ignored_assets_and_leaves_unselected_submissions_intact(self):
        subprocess.run(["git", "init", "-q", str(self.root)], check=True)
        self.put(".gitignore", b"*.json\n")
        self.put("백준/Silver/1234. 첫 문제/one.py", b"one")
        self.put("백준/Silver/1234. 첫 문제/data.json", b"fixture")
        other = self.put("백준/Silver/2345. 둘째 문제/two.py", b"two")
        organizer.organize(self.root, [1234], stage=True)
        blob = subprocess.check_output(["git", "show", ":coding-test/Baekjoon/1000/1234/data.json"], cwd=self.root)
        self.assertEqual(blob, b"fixture")
        self.assertEqual(other.read_bytes(), b"two")

    def test_codetree_links_resolve_and_regeneration_is_idempotent(self):
        tree = load("codetree", "scripts/reconcile-codetree.py")
        day = "coding-test/code_tree/250101/"
        self.put(day + "two #2/README.md", b"# Problem\n")
        self.put(day + "two #2/main.cpp", b"solve")
        text = ("# 1월 1일\n\n|커리큘럼|문제|난이도|상태|코드 링크|\n|---|---|---|---|---|\n"
                "|트레일|문제|쉬움|Solved|[링크](https://github.com/DawnteaStudio/TIL/blob/main/250101/two%20%232/main.cpp)|\n")
        daily = self.put(day + "README.md", text.encode())
        output = tree.reconcile(self.root)
        self.assertTrue(output)
        self.assertIn("(./two%20%232/main.cpp)", daily.read_text())
        self.assertIn("(./two%20%232/README.md)", daily.read_text())
        card = self.root / day / "two #2/README.md"
        self.assertTrue(card.read_text().startswith("# Problem\n"))
        self.assertIn("(./main.cpp)", card.read_text())
        self.assertIn("(../README.md)", card.read_text())
        self.assertIn("(./250101/README.md)", (self.root / "coding-test/code_tree/README.md").read_text())
        self.assertEqual(tree.reconcile(self.root), [])
        card.write_text(card.read_text().replace("# Problem", "# Problem\n\nManual approach"))
        self.put(day + "new/task.py", b"solve")
        self.put(day + "two #2/other.py", b"other solution")
        self.assertTrue(tree.reconcile(self.root))
        self.assertIn("(./new/task.py)", daily.read_text())
        self.assertIn("Manual approach", card.read_text())
        self.assertIn("(./other.py)", card.read_text())

    def test_preserves_unmanaged_bytes_and_only_localizes_exported_code_cells(self):
        tree = load("codetree", "scripts/reconcile-codetree.py")
        day = "coding-test/code_tree/250101/"
        self.put(day + "example/main.cpp", b"solve")
        old_link = "[링크](https://github.com/DawnteaStudio/TIL/blob/main/250101/example/main.cpp)"
        header = "|커리큘럼|문제|난이도|상태|코드 링크|\r\n|---|---|---|---|---|\r\n"
        row = f"|트레일|문제|쉬움|Solved|{old_link}|\r\n"
        manual = ("# 수기 제목  \r\n" + old_link + "\r\n~~~~markdown\r\n" + header + row
                  + tree.START + "\r\n~~~~\r\n" + header + row.replace("DawnteaStudio", "SomeoneElse"))
        trailer = "\r\n마지막 문장  "
        text = manual + row + tree.START + "\r\nold\r\n" + tree.END + trailer
        daily = self.put(day + "README.md", text.encode())
        card_prefix = "한 줄 소개  \r\n"
        card = self.put(day + "example/README.md", (card_prefix + tree.START + "\r\nold\r\n" + tree.END).encode())
        tree.reconcile(self.root)
        new_row = row.replace(old_link, "[문제 설명](./example/README.md) · [풀이 코드](./example/main.cpp)")
        expected = manual + new_row + tree.START + "\r\n[날짜별 풀이 목록](../README.md)\r\n" + tree.END + trailer
        self.assertEqual(daily.read_bytes(), expected.encode())
        self.assertTrue(card.read_bytes().startswith((card_prefix + tree.START + "\r\n").encode()))
        self.assertTrue(card.read_bytes().endswith(tree.END.encode()))
        self.assertEqual(tree.reconcile(self.root, check=True), [])


if __name__ == "__main__":
    unittest.main()
