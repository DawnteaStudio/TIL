[상위 README로 이동](../../README.md)

# 단테의 codex

유형: 강의

## 개요

단테의 codex 학습 내용을 정리합니다.

## 디렉터리 구조

```text

단테의-codex/

├── README.md

├── note/    # 학습 기록 Markdown

└── src/     # note와 같은 slug를 사용하는 실습 코드

```

## 작성 원칙

- 같은 학습 단위는 기본적으로 하나의 slug를 사용합니다.

- 학습 기록은 `note/<slug>.md`에 작성합니다.

- 관련 실습 코드는 `src/<slug>/` 아래에 둡니다.

- note slug와 src 폴더명이 다르면 note frontmatter의 `src` 목록으로 연결합니다.

- 예: `src: [ch1, ch2]`는 해당 note를 `src/ch1/`, `src/ch2/`와 연결합니다.

- note와 src는 어느 한쪽만 먼저 존재해도 됩니다.

- `build/`, `.gradle/`, `node_modules/`, 바이너리와 IDE 캐시는 커밋하지 않습니다.

- 학습 기록 관리 블록은 자동 생성되므로 직접 수정하지 않습니다.

---

<!-- til-studio:learning-log:start -->
## 학습 기록

| 날짜 | 주제 | src | note |
| --- | --- | --- | --- |
| 2026-07-07 | Codex 기본기: 필수 명령어와 세션 관리 | - | [codex-기본기.md](./note/codex-%EA%B8%B0%EB%B3%B8%EA%B8%B0.md) |
<!-- til-studio:learning-log:end -->
