## 🖌️ CSS JS 소개


## 📌 목차
- [1. CSS](#1-css)
  - [1-1. CSS란?](#1-1-css란)
  - [1-2. CSS inline 방식](#1-2-css-inline-방식)
  - [1-3. CSS style tag 방식](#1-3-css-style-tag-방식)
- [2. JavaScript](#2-javascript)
  - [2-1. JavaScript란?](#2-1-javascript란)
  - [2-2. JavaScript 수행 방식](#2-2-javascript-수행-방식)
- [3. 관련개념](#3-관련-개념)
- [📌 참고 자료](#-참고-자료)

---

### **1. CSS**

#### 1-1. CSS란?
- CSS (Cascading Style Sheets)는 HTML 요소의 스타일을 정의하는 스타일 시트 언어이다.
- 색상, 글꼴, 배경, 레이아웃 등을 지정하여 웹페이지를 더 보기 좋게 디자인할 수 있다.
- 코드의 재사용성을 높이고 유지보수를 쉽게 만들기 위해 사용된다. (같은 스타일을 여러 요소에 적용 가능)

#### 1-2. CSS inline 방식
- 해당 HTML 요소에 `style` 속성을 적용하여 스테일을 적용한다.

```html
<p style="color: red; font-size: 20px;">이름은 CSS inline 방식입니다.</p>
```

#### 1-3. CSS style tag 방식
- HTML 문서 안에 `<style>` 태그를 사용하여 CSS를 적용한다.

```html
<style>
p {
  color: blue;
  font-size: 18px;
}
</style>
<p>이름은 CSS style tag 방식입니다.</p>
```

---

### **2. Javascript**

#### 2-1. JavaScript란?
- JavaScript는 웹 페이지에서 동적인 기능을 추가할 수 있도록 해주는 프로그래밍 언어이다.
- 사용자 입력 처리, 애니메이션, 비동기 통신 등의 기능을 수행할 수 있다.
- 웹 브라우저뿐만 아니라 서버(Node.js)에서도 실행할 수 있다.

#### 2-2. JavaScript 수행 방식
- `<script>` 태그를 HTML 문서 내로 적용하여 실행한다.

```html
<script>
  alert("안녕하세요! JavaScript입니다.");
</script>
```

---

### **3. 관련 개념**
- **Node.js** : JavaScript를 서버 사이드에서 실행할 수 있게 해주는 오픈소스 런타임 환경.
- **동적인 기능** : 사용자 입력이나 서버 데이터에 따라 실시간으로 변화하거나 업데이트되는 웹 페이지의 요소.
- **비동기 통신** : 요청을 보낸 후 응답을 기다리지 않고 다른 작업을 수행할 수 있는 통신 방식.

---

### 📌 참고 자료
- [MDN - CSS](https://developer.mozilla.org/ko/docs/Web/CSS)
- [MDN - JavaScript](https://developer.mozilla.org/ko/docs/Web/JavaScript)
- [[인프런X생활코딩] HTML과 인터넷](https://www.inflearn.com/course/html%EA%B3%BC-%EC%9D%B8%ED%84%B0%EB%84%B7-%EC%83%9D%ED%99%9C%EC%BD%94%EB%94%A9/dashboard)

