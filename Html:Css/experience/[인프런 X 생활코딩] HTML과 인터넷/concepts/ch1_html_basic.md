## 💻 HTML의 기본기 "태그"

### **1.  태그**

#### 1-1. 태그란?

-   웹 페이지의 구조와 내용을 정의하는 기본 요소
-   각 태그는 특정한 기능을 가지고 있어 텍스트, 이미지, 링크 등을 효과적으로 표현할 수 있게 해줌
-   ex => `<tag> something </tag>`

#### 1-2. 태그 구조

-   `<tag arg="something"> content </tag>` 를 예시로 설명
-   `<tag> </tag>` 는 각각 시작 태그, 종료 태그이고, 태그의 이름을 넣는다.
-   `content` 는 태그의 내용이 들어갈 자리다.
-   `arg="something"` 에서 arg 는 tag의 속성명이 들어가는 자리고 something은 해당 속성의 속성 값이다.
-   속성명 대소문자는 HTML5에서 구분하고 있지 않다고 하나 W3C에서 소문자를 권장하므로 소문자를 사용하는 것이 좋다고 한다.
-   _참고로 W3school 에 너무 좋은 자료가 많다!_

---

### **2.  적절한 태그**

#### 2-1. 검색엔진의 간택

-   우리가 만든 웹페이지는 결국 고객들이 이용해야 가치가 생기는 것이다.
-   수십 수백억개 웹페이지 크롤러는 결국 태그를 기준으로 크롤링을 진행할 것이므로 시각적으로는 동일할 지라도 노출 여부가 매우 다를 수 있다.
-   그러므로 적절한 태그의 사용이 매우 중요하다.

#### 2-2. 웹의 접근성

-   웹은 모든 운영체제에서 동일하게 동작하는 것을 목표로 한다.
-   또 모든 기기와 장애여부와 상관없이 웹을 이용할 수 있는 것을 목표로 한다.
-   그러므로 시각적인 요소를 일차원적으로 맞추기 보단 적절한 태그를 사용해서 조작하는 것이 웹페이지에 원래 목적에 맞게 구현하기 쉽다.

---

### **3.  HTML의 구조**

#### 3-1. HTML 문서의 기본 구성

HTML 문서는 `<html>`, `<head>`, `<body>` 3가지 주요 섹션으로 구성된다.

```
<!DOCTYPE html>
<html lang="ko">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>문서 제목</title>
</head>
<body>
    <h1>제목</h1>
    <p>이곳에 본문 내용이 들어갑니다.</p>
</body>
</html>
```

✅ 주요 태그 설명

-   `<!DOCTYPE html>` : HTML5 문서임을 선언
-   `<html lang="ko">` : 문서의 언어를 한국어(ko)로 설정
-   `<head>` : 문서의 메타데이터(SEO, CSS, JavaScript 포함)를 정의
-   `<body>` : 실제 사용자에게 보이는 콘텐츠를 포함

---

#### 3-2. `<head>` 태그의 역할

`<head>` 태그에는 웹페이지의 메타정보가 포함되며, 브라우저가 문서를 올바르게 해석하는 데 도움을 준다.

#### 📌 주요 요소

```
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="이 페이지는 HTML 기본 구조를 설명합니다.">
    <meta name="keywords" content="HTML, 웹개발, 기초">
    <title>HTML 문서 구조</title>
</head>
```

-   `<meta charset="UTF-8">` : 한글을 포함한 모든 문자 인코딩을 지원
-   `<meta name="viewport">` : 반응형 웹 디자인을 위해 화면 크기 설정
-   `<meta name="description">` : 검색엔진이 문서를 이해할 수 있도록 설명 추가
-   `<meta name="keywords">` : 문서와 관련된 키워드 제공 (최근 검색엔진에서는 중요도가 낮아짐)
-   `<title>` : 웹페이지의 제목 (브라우저 탭에 표시됨)

---

#### 3-3. `<body>` 태그와 콘텐츠 구조

-   `<body>` 내부에는 실제 사용자에게 보이는 콘텐츠가 들어간다.

📌 기본적인 레이아웃 예제

```
<body>
    <header>
        <h1>웹사이트 제목</h1>
        <nav>
            <ul>
                <li><a href="#">홈</a></li>
                <li><a href="#">소개</a></li>
                <li><a href="#">연락처</a></li>
            </ul>
        </nav>
    </header>

    <main>
        <section>
            <h2>섹션 제목</h2>
            <p>이곳에 본문 내용을 추가할 수 있습니다.</p>
        </section>
    </main>

    <footer>
        <p>&copy; 2025 웹사이트. 모든 권리 보유.</p>
    </footer>
</body>
```

✅ 주요 태그 설명

-   `<header>` : 웹사이트의 상단 부분 (로고, 네비게이션 포함)
-   `<nav>` : 내비게이션 메뉴
-   `<main>` : 문서의 주요 콘텐츠 영역
-   `<section>` : 논리적인 구역을 나눌 때 사용
-   `<footer>` : 웹페이지의 하단 부분 (저작권 정보 등)

---

### **4\. 관련 개념**

-   **W3C**: 웹 기술의 표준화와 발전을 위해 다양한 이해관계자들이 모여 웹의 상호 운용성과 접근성을 증진하는 국제 기구
-   **웹브라우저 크롤러**: 웹 페이지를 자동으로 탐색하고 데이터를 수집하여 검색 엔진의 인덱스를 생성하는 소프트웨어 프로그램
-   **메타데이터**: 데이터에 대한 정보를 설명하는 데이터로, 주로 데이터의 구조, 내용, 출처 등을 정의하여 이해와 관리를 도움

---

#### 📌 참고 자료

-   [MDN - 웹의 동작 원리](https://developer.mozilla.org/ko/docs/Learn/Getting_started_with_the_web/How_the_Web_works)
-   [TCPSCHOOL - HTML 태그](https://tcpschool.com/html-tags/intro)
-   [\[인프런X생활코딩\] HTML과 인터넷](https://www.inflearn.com/course/html%EA%B3%BC-%EC%9D%B8%ED%84%B0%EB%84%B7-%EC%83%9D%ED%99%9C%EC%BD%94%EB%94%A9/dashboard)