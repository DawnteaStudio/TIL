# Markdown 작성 템플릿

[전체 학습 목차](../README.md)

| 새로 만들 문서 | 템플릿 | 저장 위치 |
| --- | --- | --- |
| CS 또는 프로젝트 주제의 목차 | [주제 README](template.md) | 분야/주제/README.md |
| 프로그래밍 언어의 목차 | [언어 README](template_lan.md) | languages/언어/README.md |
| 책·강의의 노트와 실습 목록 | [자료 README](template_leaf.md) | 분야/주제/notes/자료명/README.md |

학습 노트는 아래 예처럼 작성합니다. 실제 작성일을 적고, 실습 이름이 파일명과 다르거나 여러 개일 때 `src`를 지정합니다. 이론 글에는 개념, 동작을 확인한 예, 적용 조건과 출처를 담고 해당하는 항목만 남깁니다.

```markdown
---
created: 2026-01-15
src: [ch1]
---

# 클래스와 인스턴스

클래스는 인스턴스가 가질 필드와 메소드를 정의한다.
```

[실제 Java 노트와 실습 연결 예시](../languages/java/notes/java-basic/README.md)
