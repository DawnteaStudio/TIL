[상위 README로 이동](../../README.md)

# Source Smoke

유형: 기타

## 개요

Temporary README cascade test

## 디렉터리 구조

```text

source-smoke/

├── README.md

├── note/    # 학습 기록 Markdown

└── src/     # note와 같은 slug를 사용하는 실습 코드

```

## 작성 원칙

- 같은 학습 단위는 하나의 slug를 사용합니다.

- 학습 기록은 `note/<slug>.md`에 작성합니다.

- 관련 실습 코드는 `src/<slug>/` 아래에 둡니다.

- note와 src는 어느 한쪽만 먼저 존재해도 됩니다.

- `build/`, `.gradle/`, `node_modules/`, 바이너리와 IDE 캐시는 커밋하지 않습니다.

- 학습 기록 관리 블록은 자동 생성되므로 직접 수정하지 않습니다.

---

<!-- til-studio:learning-log:start -->
## 학습 기록

| 날짜 | 학습 내용 | 소스 코드 | 노트 |
| --- | --- | --- | --- |
| 2026-06-11 | Nested README cascade smoke test | - | [note-smoke.md](./note/note-smoke.md) |
<!-- til-studio:learning-log:end -->
