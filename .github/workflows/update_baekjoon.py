"""Archive imported problem files without overwriting solutions or losing statements."""
import argparse
import filecmp
import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile


PLATFORMS = {"백준": "Baekjoon", "프로그래머스": "Programmers"}
SOLUTION_EXTENSIONS = {".c", ".cc", ".cpp", ".py", ".java", ".txt", ".js", ".ts",
                       ".kt", ".go", ".rs", ".cs", ".sql", ".swift", ".rb"}
PROBLEM_NAME = re.compile(r"(\d+)[.\s]\s*(\S.*)")


def identical(first, second):
    return (first.is_file() and second.is_file()
            and (first.stat().st_mode & 0o111) == (second.stat().st_mode & 0o111)
            and filecmp.cmp(first, second, shallow=False))


def check_target(root, target):
    for ancestor in (target, *target.parents):
        if ancestor == root:
            break
        if ancestor.is_symlink() or (ancestor != target and ancestor.exists() and not ancestor.is_dir()):
            raise ValueError(f"대상 경로 충돌: {ancestor}")


def plan_files(root, numbers):
    copies = {}
    originals = {}
    for incoming, platform in PLATFORMS.items():
        base = root / incoming
        if base.is_symlink():
            raise ValueError(f"가져오기 경로가 심볼릭 링크입니다: {base}")
        if not base.is_dir():
            continue
        for level in sorted(base.iterdir()):
            if level.is_symlink() or not level.is_dir():
                continue
            for problem in sorted(level.iterdir()):
                match = PROBLEM_NAME.fullmatch(problem.name)
                if not match or problem.is_symlink() or not problem.is_dir():
                    continue
                number = int(match.group(1))
                if numbers and number not in numbers:
                    continue
                if not any(p.is_file() and p.suffix.lower() in SOLUTION_EXTENSIONS for p in problem.iterdir()):
                    continue
                group = str(number // 1000 * 1000) if platform == "Baekjoon" else level.name
                directory = root / "coding-test" / platform / group
                for src in sorted(problem.rglob("*")):
                    rel = src.relative_to(problem)
                    if src.is_symlink() or ".git" in (part.casefold() for part in rel.parts):
                        raise ValueError(f"자동 보관할 수 없는 파일입니다: {src}")
                    if src.is_dir():
                        continue
                    if not src.is_file():
                        raise ValueError(f"일반 파일이 아닙니다: {src}")
                    # Preserve the original directory and names so relative links in statements still work.
                    targets = [directory / str(number) / rel]
                    ext = src.suffix.lower()
                    if src.parent == problem and ext in SOLUTION_EXTENSIONS:
                        if platform == "Baekjoon" and ext == ".cc":
                            ext = ".cpp"
                        targets.append(directory / f"{number}{ext}")
                    for target in targets:
                        check_target(root, target)
                        other = copies.get(target)
                        if other is not None and not identical(src, other):
                            raise ValueError(f"두 원본의 대상이 겹칩니다: {src}, {other} → {target}")
                        if target.exists() and not identical(src, target):
                            raise ValueError(f"대상에 다른 내용이 있습니다: {target}")
                        copies[target] = src
                    originals[src] = targets[0]
    for target in copies:
        if any(parent in copies for parent in target.parents):
            raise ValueError(f"파일과 폴더가 같은 경로를 사용합니다: {target}")
    return copies, originals


def copy_exclusively(src, dest):
    if dest.exists():
        if not identical(src, dest):
            raise ValueError(f"대상 파일이 변경되었습니다: {dest}")
        return
    dest.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile(dir=dest.parent, delete=False) as staged:
        temporary = Path(staged.name)
    try:
        shutil.copy2(src, temporary)
        try:
            # Publish the complete file only if the destination is still free.
            os.link(temporary, dest)
        except FileExistsError:
            if not identical(src, dest):
                raise ValueError(f"대상 파일이 변경되었습니다: {dest}")
    finally:
        temporary.unlink()


def organize(root, numbers=(), stage=False):
    root = Path(root).resolve()
    copies, originals = plan_files(root, numbers)
    for dest, src in copies.items():
        copy_exclusively(src, dest)
    # Keep tracked sidecars even if a destination matches .gitignore (for example, *.json).
    if stage and copies:
        paths = b"".join(os.fsencode(p.relative_to(root)) + b"\0" for p in copies)
        subprocess.run(["git", "--literal-pathspecs", "add", "-f", "--pathspec-from-file=-",
                        "--pathspec-file-nul"], cwd=root, input=paths, check=True)
    if (not all(identical(src, dest) for dest, src in copies.items()) or
            not all(identical(src, archived) for src, archived in originals.items())):
        raise ValueError("복사본 검증에 실패했습니다. 원본을 보존합니다.")
    for src in sorted(originals):
        src.unlink()
    return sorted(copies)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--numbers", type=int, nargs="*", default=[])
    parser.add_argument("--stage", action="store_true", help="stage checked archive copies, including ignored sidecars")
    args = parser.parse_args()
    try:
        changed = organize(Path.cwd(), args.numbers, args.stage)
        print(f"보관 완료: 대상 파일 {len(changed)}개")
    except (OSError, ValueError, subprocess.CalledProcessError) as exc:
        parser.exit(1, f"보관을 중단했습니다: {exc}\n")
