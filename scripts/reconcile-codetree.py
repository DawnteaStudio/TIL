"""Keep CodeTree exports navigable after they move into coding-test/code_tree."""
import argparse
from datetime import datetime
from pathlib import Path
import re
from urllib.parse import quote, unquote, urlsplit


START = "<!-- codetree:navigation:start -->"
END = "<!-- codetree:navigation:end -->"
OLD_CODE_CELL = re.compile(r"(?<=\|)([ \t]*)\[링크\]\((https://github\.com/DawnteaStudio/TIL/blob/main/[^)\s]+)\)(?=[ \t]*\|[ \t]*$)")
EXPORT_HEADER = ["커리큘럼", "문제", "난이도", "상태", "코드 링크"]
EXTENSIONS = {".cpp", ".cc", ".c", ".java", ".py", ".kt", ".js", ".ts", ".go", ".rs", ".swift", ".cs"}


def href(relative):
    return "./" + quote(relative.as_posix(), safe="/")


def label(text):
    return text.replace("\\", "\\\\").replace("[", "\\[").replace("]", "\\]").replace("|", "\\|")


def read_page(path):
    if path.is_symlink():
        raise ValueError(f"심볼릭 링크 문서는 자동 갱신하지 않습니다: {path}")
    return path.read_bytes().decode("utf-8") if path.is_file() else ""


def markdown_lines(text):
    """Yield original lines and identify lines outside Markdown and HTML code blocks."""
    fence = None
    html_tag = None
    for line in text.splitlines(keepends=True):
        content = line.rstrip("\r\n")
        delimiter = re.match(r"^ {0,3}(`{3,}|~{3,})(.*)$", content)
        if html_tag:
            if f"</{html_tag}>" in content.lower():
                html_tag = None
            yield line, False
        elif fence:
            if delimiter and delimiter[1].startswith(fence) and not delimiter[2].strip():
                fence = None
            yield line, False
        elif delimiter:
            fence = delimiter[1]
            yield line, False
        elif tag := re.match(r"^ {0,3}<(pre|code)\b", content, re.I):
            if f"</{tag[1].lower()}>" not in content.lower():
                html_tag = tag[1].lower()
            yield line, False
        else:
            yield line, not content.startswith(("    ", "\t"))


def split_managed(text):
    markers, offset = [], 0
    for line, markdown in markdown_lines(text):
        content = line.rstrip("\r\n")
        if markdown and content in (START, END):
            markers.append((content, offset))
        offset += len(line)
    if not markers:
        return text, None
    if [name for name, _ in markers] != [START, END]:
        raise ValueError("CodeTree 탐색 영역의 시작·종료 표시를 확인하세요.")
    return text[:markers[0][1]], text[markers[1][1] + len(END):]


def with_block(before, after, body, original):
    first_break = re.search(r"\r\n|\n|\r", original)
    eol = first_break[0] if first_break else "\n"
    block = eol.join([START, *body.split("\n"), END])
    if after is not None:
        return before + block + after
    separator = "" if not before or before.endswith(eol * 2) else eol if before.endswith(eol) else eol * 2
    ending = eol if not original or original.endswith(("\r", "\n")) else ""
    return before + separator + block + ending


def localize_export_table(text, replace):
    output, in_export = [], False
    for line, markdown in markdown_lines(text):
        content = line.rstrip("\r\n")
        if not markdown or not content.startswith("|"):
            in_export = False
        elif [cell.strip() for cell in content.strip("|").split("|")] == EXPORT_HEADER:
            in_export = True
        elif in_export:
            line = OLD_CODE_CELL.sub(replace, content) + line[len(content):]
        output.append(line)
    return "".join(output)


def daily_page(day, current):
    before, after = split_managed(current)
    if not current:
        before = f"# {day.name} CodeTree 풀이\n"
    problems = {}
    for directory in sorted(day.iterdir()):
        if directory.name.startswith(".") or not directory.is_dir() or directory.is_symlink():
            continue
        sources = [p.relative_to(day) for p in sorted(directory.iterdir())
                   if p.is_file() and not p.is_symlink() and p.suffix.lower() in EXTENSIONS]
        if sources or (directory / "README.md").is_file():
            problems[directory.name] = sources

    def localize(match):
        exported = unquote(urlsplit(match.group(2)).path)
        prefix = f"/DawnteaStudio/TIL/blob/main/{day.name}/"
        if not exported.startswith(prefix):
            return match.group(0)
        for name, sources in problems.items():
            for source in sources:
                if exported == prefix + source.as_posix():
                    problem = Path(name) / "README.md"
                    return f"{match.group(1)}[문제 설명]({href(problem)}) · [풀이 코드]({href(source)})"
        raise ValueError(f"{day.name} 원본 코드 경로를 찾을 수 없습니다: {match.group(2)}")

    before = localize_export_table(before, localize)
    if after is not None:
        after = localize_export_table(after, localize)
    manual = before + (after or "")
    body = ["[날짜별 풀이 목록](../README.md)"]
    extra = []
    for name, sources in problems.items():
        problem = Path(name) / "README.md"
        # Keep the exported status table. Add only documents or solutions it does not already link.
        missing = [source for source in sources if f"({href(source)})" not in manual]
        if missing or f"({href(problem)})" not in manual:
            links = " · ".join(f"[{label(p.name)}]({href(p)})" for p in missing)
            row = f"- [{label(name)}]({href(problem)})"
            extra.append(f"{row} · {links}" if links else row)
    if extra:
        body.extend(["", "## 추가 문제와 풀이", "", *extra])
    return with_block(before, after, "\n".join(body), current), problems


def reconcile(root, check=False):
    tree = Path(root) / "coding-test" / "code_tree"
    if tree.is_symlink() or tree.parent.is_symlink():
        raise ValueError(f"CodeTree 경로가 심볼릭 링크입니다: {tree}")
    if not tree.is_dir():
        return []
    updates = {}
    rows = []
    for day in sorted(tree.iterdir(), reverse=True):
        if not re.fullmatch(r"\d{6}", day.name) or not day.is_dir() or day.is_symlink():
            continue
        formatted = datetime.strptime(day.name, "%y%m%d").date().isoformat()
        path = day / "README.md"
        old = read_page(path)
        new, problems = daily_page(day, old)
        if old != new:
            updates[path] = new
        for name, sources in problems.items():
            card = day / name / "README.md"
            old_card = read_page(card)
            before, after = split_managed(old_card or f"# {label(name)}\n")
            links = ["[이날의 문제 목록](../README.md)"]
            for source in sources:
                filename = Path(source.name)
                links.append(f"[풀이 코드 · {label(source.name)}]({href(filename)})")
            new_card = with_block(before, after, " · ".join(links), old_card)
            if old_card != new_card:
                updates[card] = new_card
        rows.append(f"| [{formatted}]({href(Path(day.name) / 'README.md')}) | {len(problems)} |")
    index = tree / "README.md"
    old = read_page(index)
    before, after = split_managed(old or "# CodeTree 풀이\n")
    body = "\n".join(["[코딩 테스트 목록](../README.md)", "", "| 학습 날짜 | 문제 수 |", "| --- | ---: |", *rows])
    new = with_block(before, after, body, old)
    if old != new:
        updates[index] = new
    if not check:
        for path, text in updates.items():
            path.write_bytes(text.encode("utf-8"))
    return list(updates)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    changes = reconcile(Path.cwd(), args.check)
    for path in changes:
        print(path.relative_to(Path.cwd()))
    if args.check and changes:
        parser.exit(1, "CodeTree 목차를 갱신해야 합니다.\n")
