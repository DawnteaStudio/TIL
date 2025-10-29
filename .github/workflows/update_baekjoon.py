import os
import re
import shutil
import subprocess
from datetime import datetime

# BAEKJOON_ID = "012vision"
# git reset --hard HEAD~1
# git push -f origin master

# TODO: 본인 깃허브 사용자 / 저장소명 (현재 코드에서는 미사용)
GITHUB_USER = "DawnteaStudio"
REPOSITORY_NAME = "TIL"

# TODO: 원래경로 / 이동경로 / 탐색할 확장자
SOURCE_ROOT = "백준"
TARGET_ROOT = "coding-test/Baekjoon"
SOLUTION_EXTENSIONS = ('.cpp', '.cc', '.py', '.c', '.java', '.txt')

LEVEL_FORMAT = "{level}"        # 난이도 표시 (예: Bronze)
NUM_FORMAT = "{num}"            # 문제 번호 (예: 10804)
TITLE_FORMAT = "{title}"        # 문제 제목 (예: 카드 역배치)
EXT_FORMAT = "{ext}"            # 확장자 (예: .cpp)

# 파일명 포맷 설정
# FILE_NAME_FORMAT = f"{LEVEL_FORMAT}. {NUM_FORMAT}_{TITLE_FORMAT}{EXT_FORMAT}"
FILE_NAME_FORMAT = f"{NUM_FORMAT}{EXT_FORMAT}"  # 10804.cpp

# 폴더 포맷 설정
SUB_FOLDER_PATH_FORMAT = "{sub_folder}"  # get_sub_folder함수에 정의함
FOLDER_PATH_FORMAT = os.path.join(TARGET_ROOT, SUB_FOLDER_PATH_FORMAT)

def ensure_git_identity():
    """로컬 git 사용자 설정(액션 환경/로컬 모두 안전)."""
    subprocess.run(["git", "config", "--local", "user.email", "action@github.com"], check=True)
    subprocess.run(["git", "config", "--local", "user.name", "GitHub Action"], check=True)

# 문제 번호를 기준으로 1000 단위 하위 폴더 계산
def get_sub_folder(num: int) -> str:
    return str((num // 1000) * 1000)  # ex) 10804 → '10000'

# 경로에서 난이도, 번호, 제목, 확장자 추출
def extract_problem_info(file_path: str):
    rel_path = os.path.relpath(file_path, SOURCE_ROOT)
    parts = rel_path.split(os.sep)
    if len(parts) < 3:
        return None

    level = parts[0]
    folder_name = parts[1]

    match = re.match(r'(\d+)\s*[.\s]\s*(.+)', folder_name)
    if match:
        num = int(match.group(1))
        title = match.group(2).replace(' ', '_')
    else:
        num, title = None, ""

    ext = os.path.splitext(file_path)[1]
    return {"level": level, "num": num, "title": title, "ext": ext}

# 지정된 파일의 커밋 메시지와 시간 가져오기
def get_commit_info(path: str):
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
            msg = "Auto organize Baekjoon files"
        if not time_str:
            time_str = datetime.now().isoformat()

        return {"message": msg, "time": time_str}

    except Exception as e:
        print(f"[경고] 커밋 정보 조회 실패: {e}")
        return {
            "message": "Auto organize Baekjoon files",
            "time": datetime.now().isoformat()
        }

# 새 파일명과 폴더 경로 생성
def get_new_paths(problem_info: dict):
    num = problem_info["num"]
    title = problem_info["title"]
    level = problem_info["level"]
    ext = problem_info["ext"]

    # 하위 폴더명 가져오기
    sub_folder = get_sub_folder(num)

    # 파일명 포맷 적용
    file_name = FILE_NAME_FORMAT.format(level=level, num=num, title=title, ext=ext)
    file_name = re.sub(r'[\\/:*?"<>|]', '_', file_name)

    # 폴더 경로 생성
    folder_path = FOLDER_PATH_FORMAT.format(sub_folder=sub_folder)
    os.makedirs(folder_path, exist_ok=True)

    new_path = os.path.join(folder_path, file_name)
    return {"folder": folder_path, "file": new_path}

# 풀이 파일 이동 및 파일별 개별 커밋 수행
def move_and_commit():
    if not os.path.isdir(SOURCE_ROOT):
        print(f"원본 폴더가 없습니다: {SOURCE_ROOT}")
        return

    # ✅ 커밋 전 Git 사용자 설정
    ensure_git_identity()

    moved_files = []

    # 백준 폴더 탐색
    for root, _, files in os.walk(SOURCE_ROOT):
        for file in files:
            if not file.lower().endswith(SOLUTION_EXTENSIONS):
                continue

            file_path = os.path.join(root, file)
            problem_info = extract_problem_info(file_path)
            if not problem_info or problem_info["num"] is None:
                continue

            # 커밋 시간은 기존 파일의 마지막 커밋에서 가져오되,
            # 메시지는 "<번호> solve"로 강제
            commit = get_commit_info(file_path)

            # 새 파일 경로 생성 및 이동
            new_paths = get_new_paths(problem_info)
            shutil.move(file_path, new_paths["file"])

            # 메시지 덮어쓰기: "12345 solve"
            commit["message"] = f"{problem_info['num']} solve"

            moved_files.append({
                "old": file_path,
                "new": new_paths["file"],
                "commit": commit,
                "info": problem_info
            })

    # 파일별 개별 커밋 (실패 시 즉시 중단)
    for f in moved_files:
        subprocess.run(["git", "add", f["new"]], check=True)
        subprocess.run([
            "git", "commit",
            "-m", f"{f['commit']['message']}",
            "--date", f"{f['commit']['time']}"
        ], check=True)

    if moved_files:
        print(f"\n총 {len(moved_files)}개 파일 이동 및 커밋 완료.")
        for f in moved_files:
            print(f"- {f['info']['level']} | {f['info']['num']} | {f['info']['title']} | {f['commit']['time']}")
    else:
        print("이동할 파일이 없습니다.")

# 백준 폴더 전체를 삭제하고, 변경사항을 커밋 및 푸시
def remove_baekjoon_folder(base_path: str = "백준"):
    if not os.path.exists(base_path):
        print(f"[오류] 경로가 존재하지 않습니다: {base_path}")
        return

    try:
        # 폴더 전체 삭제
        shutil.rmtree(base_path)
        print(f"🗑️ '{base_path}' 폴더 전체 삭제 완료.")

        # ✅ 커밋 전 Git 사용자 설정
        ensure_git_identity()

        # 삭제 변경만 스테이징 (폴더가 사라졌어도 pathspec으로 삭제 기록 가능)
        subprocess.run(["git", "add", "-A", "--", base_path], check=True)

        # 변경사항 확인 후 커밋 + 푸시
        diff = subprocess.run(["git", "diff", "--cached", "--quiet"])
        if diff.returncode != 0:
            subprocess.run(["git", "commit", "-m", "[chore] 백준 폴더 삭제"], check=True)
            subprocess.run(["git", "push"], check=True)
            print("✅ 백준 폴더 삭제 및 커밋/푸시 완료.")
        else:
            print("⚪ 변경사항이 없습니다. 커밋 생략.")

    except Exception as e:
        print(f"❌ 백준 폴더 삭제 중 오류 발생: {e}")

if __name__ == "__main__":
    move_and_commit()
    remove_baekjoon_folder(SOURCE_ROOT)
