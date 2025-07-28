[⬅️ 상위 README로 이동](../README.md)

## 📘 align-items vs align-content

## 📌 목차

* [0. 요약](#0-요약)
* [1. 기본 개념](#1-기본-개념)
* [2. 각 속성 설명](#2-각-속성-설명)
* [3. 시각적-비교-결과](#3-시각적-비교-결과)
* [4. 관련 개념](#4-관련-개념)
* [📌 참고 자료](#📌-참고-자료)

---

### **0. 요약**

🔍 쉽게 말해보면
- align-items → 한 줄 내의 아이템들을 세로로 어떻게 정렬할까? → 줄 안에서 어떻게 서 있을까?
- align-content → 줄과 줄 사이 간격을 세로로 어떻게 정렬할까? → 줄 덩어리 전체를 어떻게 위치시킬까?


### **1. 기본 개념**

| 속성              | 적용 대상              | 작용 조건                     | 작용 방향                                   |
| --------------- | ------------------ | ------------------------- | --------------------------------------- |
| `align-items`   | 각 아이템(item)       | 항상                        | 그래프의 규칙에서 **가로선 아닌 세로 방향 (cross axis)** |
| `align-content` | 열(Row) 전체 | `flex-wrap`이 `wrap` 일 경우만 | 규칙에서 **가로선 아닌 세로 방향 (cross axis)**      |

---

### **2. 각 속성 설명**

#### ✅ `align-items`

* 세로방향(cross axis)에서 **각 아이템(item)** 의 위치를 정하는 속성
* 예를 들어, `align-items: center`를 설정하면 각 아이템이 **각 줄 안에서 세로 가운데로** 정렬된다

```css
.container {
  display: flex;
  align-items: center;
}
```

#### ✅ `align-content`

* **열 (row)이 여러 줄일 경우**, 매 열과 열 사이의 **간격**을 어떻게 정렬할것인지 정하는 속성
* 각 아이템이 아닌, **열(줄)과 열 사이 간격 정렬에 영향**
* `flex-wrap: wrap` 가 필요

```css
.container {
  display: flex;
  flex-wrap: wrap;
  height: 300px;
  align-content: space-between;
}
```

---

### **3. 시각적 그림 비교 결과**

#### 형식: 6개의 box, wrap가 하여 2줄이 되는 Flex container

##### ▶ `align-items: center`

```
+----------------------------+  ← 보복면 300px
|                            |
|  [□] [□] [□]           | ← 줄1: 아이템이 세로 가운데
|                            |
|  [□] [□] [□]           | ← 줄2: 아이템이 세로 가운데
|                            |
+----------------------------+
```

##### ▶ `align-content: center`

```
+----------------------------+  ← 보복면 300px
|                            |
|                            |  ← 상단 여보
|  [□] [□] [□]           | ← 줄1
|  [□] [□] [□]           | ← 줄2
|                            |  ← 하단 여보
|                            |
+----------------------------+
```

---

### **4. 관련 개념**

* `justify-content`: 주 축(가로) 방향의 정렬
* `align-self`: 각 아이템에 대해 `align-items`를 무시하고 계산

---

## 📌 참고 자료

* [MDN - align-items](https://developer.mozilla.org/en-US/docs/Web/CSS/align-items)
* [MDN - align-content](https://developer.mozilla.org/en-US/docs/Web/CSS/align-content)
* [CSS Tricks Flexbox Guide](https://css-tricks.com/snippets/css/a-guide-to-flexbox/)
