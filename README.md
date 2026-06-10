# Today I Learned (TIL)

컴퓨터공학, 프로그래밍 언어, 문제 풀이, 프로젝트 경험을 차곡차곡 정리하는 학습 저장소입니다.

이 저장소는 공부 중 남긴 기록을 바로 버리지 않고 `notes/`에 쌓아두고, 충분히 이해한 내용은 `theory/`로 정제해 다시 찾기 쉽게 만드는 것을 목표로 합니다.

---

## 작성 원칙

- `theory/`: 여러 자료를 바탕으로 정리한 개념 문서
- `notes/`: 강의, 책, 학습 중 작성한 기록
- `notes/[자료명]/note/`: 글 형태의 학습 기록
- `notes/[자료명]/src/`: note와 연결되는 실행 코드와 실습 파일
- `coding-test/`: 백준, 프로그래머스, 코드트리 등 문제 풀이
- `projects/`: 프로젝트 경험, 회고, 트러블슈팅
- note와 src는 대소문자를 포함해 slug가 정확히 같을 때만 연결
- 각 source의 `README.md` 학습 기록은 til-studio와 GitHub Action이 관리

---

## 링크 모음

| 디렉토리 | 설명 | 링크 |
| --- | --- | --- |
| `cs/` | 알고리즘, 자료구조, 운영체제, 네트워크 등 CS 학습 | [바로가기](./cs/) |
| `languages/` | C, C++, Python, JavaScript, HTML/CSS 등 언어 학습 | [바로가기](./languages/) |
| `coding-test/` | 실전 문제 풀이와 풀이 회고 | [바로가기](./coding-test/) |
| `projects/` | 프로젝트 경험과 기록 | [바로가기](./projects/) |
| `templates/` | 새 주제와 자료를 추가할 때 사용하는 템플릿 | [바로가기](./templates/) |

---

## 디렉토리 구조

```text
TIL/
├── cs/
│   ├── algorithms/
│   │   ├── README.md
│   │   ├── theory/
│   │   └── notes/
│   │       └── [자료명]/
│   │           ├── README.md
│   │           ├── note/
│   │           │   └── [slug].md
│   │           └── src/
│   │               └── [slug]/
│   ├── databases/
│   └── ...
│
├── languages/
│   ├── javascript/
│   │   ├── README.md
│   │   ├── theory/
│   │   └── notes/
│   └── ...
│
├── coding-test/
├── projects/
├── templates/
└── README.md
```

---

## 정리 흐름

1. 강의나 책을 공부할 때는 `notes/[자료명]/note/[slug].md`에 기록합니다.
2. 글과 연결되는 코드는 `notes/[자료명]/src/[slug]/`에 둡니다.
3. note에는 `created: YYYY-MM-DD` frontmatter를 기록합니다.
4. source README의 `til-studio:learning-log` marker 사이는 직접 수정하지 않습니다.
5. 여러 기록을 다시 읽고 개념이 정리되면 `theory/`에 독립 문서로 옮깁니다.
6. 문제 풀이는 주제 이론과 섞지 않고 `coding-test/`에 따로 관리합니다.
7. 프로젝트에서 배운 내용은 `projects/`에 경험 중심으로 정리합니다.

<!-- til-studio:children:start -->
## 하위 항목

- [action-chain-smoke](action-chain-smoke/)
- [coding-test](coding-test/)
- [cs](cs/)
- [languages](languages/)
- [projects](projects/)
<!-- til-studio:children:end -->
