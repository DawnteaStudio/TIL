import os
import re
import shutil
import subprocess
from datetime import datetime
from typing import Optional, Dict, Any, List

# ===== 설정 =====
SOLUTION_EXTENSIONS = ('.cpp', '.cc', '.py', '.c', '.java', '.txt')

# 파일명 포맷 (공통)
FILE_NAME_FORMAT = "{num}{ext}"  # 예: 10804.cpp

# 소스별 설정: source_root, target_root, subfolder 규칙
SOURCES = [
    {
        "name": "백준",
        "source_root": "백준",
        "target_root": "coding-test/Baekjoon",
        # 하위 폴더: 1000 단위
        "subfolder": lambda info: str((info["num"] // 1000) * 1000),
        # 폴더명 패턴: "숫자. 제목"
        "folder_regex": r'(\d+)\s*[.\s]\s*(.+)',
        # 삭제 후 커밋 메시지
        "delete_message": "[chore] 백준 폴더 삭제",
        "ext_map": {".cc": ".cpp"},
    },
    {
        "name": "프로그래머스",
        "source_root": "프로그래머스",
        "target_root": "coding-test/Programmers",
        # 하위 폴더: 난이도(폴더 첫 세그먼트)
        "subfolder": lambda info: info["level"],
        # 폴더명 패턴: "숫자. 제목"
        "folder_regex": r'(\d+)\s*[.\s]\s*(.+)',
        "delete_message": "[chore] 프로그래머스 폴더 삭제",
    },
]

# ============= 공통 유틸 =============
def ensure_git_identity():
    """로컬 git 사용자 설정."""
    subprocess.run(["git", "config", "--local", "user.email", "action@github.com"], check=True)
    subprocess.run(["git", "config", "--local", "user.name", "GitHub Action"], check=True)

def get_commit_info(path: str) -> Dict[str, str]:
    """지정 경로의 마지막 커밋 메시지/시간. 없으면 기본값."""
    try:
        msg_proc = subprocess.run(
            ["git", "log", "-1", "--pretty=%B", "--", path],
            capture_output=True, text=True, encoding="utf-8", check=False
        )
        msg = (msg_proc.stdout or "").strip()

        time_proc = subprocess.run(
            ["git", "log", "-1", "--pretty=%ci", "--", path],
            capture_output=True, text=True, encoding="utf-8", check=False
        )
        time_str = (time_proc.stdout or "").strip()

        if not msg:
            msg = "Auto organize coding-test files"
        if not time_str:
            time_str = datetime.now().isoformat()

        return {"message": msg, "time": time_str}
    except Exception as e:
        print(f"[경고] 커밋 정보 조회 실패: {e}")
        return {"message": "Auto organize coding-test files",
                "time": datetime.now().isoformat()}

def parse_problem_info(source_cfg: Dict[str, Any], file_path: str) -> Optional[Dict[str, Any]]:
    """경로에서 (레벨/번호/제목/확장자) 추출."""
    source_root = source_cfg["source_root"]
    rel_path = os.path.relpath(file_path, source_root)
    parts = rel_path.split(os.sep)
    # 예상: <level>/<num. title>/파일명
    if len(parts) < 3:
        return None

    level = parts[0]  # 백준: Bronze/Silver...   프로그래머스: 1/2/3/4...
    folder_name = parts[1]  # "42895. N으로 표현"
    m = re.match(source_cfg["folder_regex"], folder_name)
    if not m:
        return None

    num = int(m.group(1))
    title = m.group(2).strip().replace(' ', '_')
    ext = os.path.splitext(file_path)[1]
    return {"level": level, "num": num, "title": title, "ext": ext}

def build_new_path(source_cfg: Dict[str, Any], info: Dict[str, Any]) -> str:
    """대상 경로(폴더 생성 포함)와 파일명 생성."""
    target_root = source_cfg["target_root"]
    subfolder = source_cfg["subfolder"](info)

    file_name = FILE_NAME_FORMAT.format(
        num=info["num"], ext=info["ext"], title=info["title"], level=info["level"]
    )
    file_name = re.sub(r'[\\/:*?"<>|]', '_', file_name)

    folder_path = os.path.join(target_root, str(subfolder))
    os.makedirs(folder_path, exist_ok=True)
    return os.path.join(folder_path, file_name)

# ============= 주 로직 =============
def move_and_commit_for_source(source_cfg: Dict[str, Any]) -> List[Dict[str, Any]]:
    """한 소스(백준/프로그래머스)에 대해 파일 이동 + 개별 커밋."""
    source_root = source_cfg["source_root"]

    if not os.path.isdir(source_root):
        print(f"원본 폴더가 없습니다: {source_root}")
        return []

    ensure_git_identity()

    moved: List[Dict[str, Any]] = []
    for root, _, files in os.walk(source_root):
        for file in files:
            if not file.lower().endswith(SOLUTION_EXTENSIONS):
                continue
            file_path = os.path.join(root, file)

            info = parse_problem_info(source_cfg, file_path)
            if not info or info["num"] is None:
                continue

            commit = get_commit_info(file_path)
            new_path = build_new_path(source_cfg, info)

            # 이동
            os.makedirs(os.path.dirname(new_path), exist_ok=True)
            shutil.move(file_path, new_path)

            # 커밋 메시지 강제: "<번호> solve"
            commit["message"] = f"{info['num']} solve"

            # 개별 커밋
            subprocess.run(["git", "add", new_path], check=True)
            subprocess.run([
                "git", "commit",
                "-m", commit["message"],
                "--date", commit["time"]
            ], check=True)

            moved.append({
                "old": file_path,
                "new": new_path,
                "info": info,
                "commit": commit,
                "source": source_cfg["name"],
            })

    if moved:
        print(f"\n[{source_cfg['name']}] 총 {len(moved)}개 파일 이동 및 커밋 완료.")
        for f in moved:
            print(f"- {f['source']} | {f['info']['level']} | {f['info']['num']} | {f['info']['title']} | {f['commit']['time']}")
    else:
        print(f"[{source_cfg['name']}] 이동할 파일이 없습니다.")
    return moved

def delete_source_folder(source_cfg: Dict[str, Any]):
    """소스 루트 폴더 전체 삭제 + 분리 커밋."""
    base_path = source_cfg["source_root"]
    if not os.path.exists(base_path):
        print(f"[오류] 경로가 존재하지 않습니다: {base_path}")
        return

    try:
        shutil.rmtree(base_path)
        print(f"🗑️ '{base_path}' 폴더 전체 삭제 완료.")

        ensure_git_identity()
        # 삭제만 스테이징
        subprocess.run(["git", "add", "-A", "--", base_path], check=True)

        diff = subprocess.run(["git", "diff", "--cached", "--quiet"])
        if diff.returncode != 0:
            subprocess.run(["git", "commit", "-m", source_cfg["delete_message"]], check=True)
            subprocess.run(["git", "push"], check=True)
            print(f"✅ {base_path} 삭제 커밋/푸시 완료.")
        else:
            print("⚪ 변경사항이 없습니다. 커밋 생략.")
    except Exception as e:
        print(f"❌ '{base_path}' 폴더 삭제 중 오류 발생: {e}")

def main():
    any_moved = False
    for src in SOURCES:
        moved = move_and_commit_for_source(src)
        if moved:
            any_moved = True
        # 원본 폴더 삭제까지 수행 (원치 않으면 이 줄 주석 처리)
        delete_source_folder(src)

    if not any_moved:
        print("모든 소스에서 이동할 파일이 없습니다.")

if __name__ == "__main__":
    main()

