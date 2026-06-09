---
created: 2024-03-20
---

[⬅️ 상위 README로 이동](../README.md)

## 📘 C 언어: 조건문 정리

## 📌 목차

* [1. if, if else, if else if else](#1-if-if-else-if-else-if-else)
* [2. switch case 문](#2-switch-case-문)
* [📌 참고 자료](#-참고-자료)

---

## **1. if, if else, if else if else**

- 조건에 따라 코드의 흐름을 제어할 때 사용하는 대표 문법
- `if (조건)`이 `true`이면 중괄호 `{}` 내 코드를 실행

```c
#include <stdio.h>

int main() {
    int a = 10;

    if (a > 0)
        printf("it's true!\n");

    if (a > 20)
        printf("it's false!\n"); // 실행되지 않음
}
```

- 실행 문장이 한 줄이면 중괄호 `{}` 생략 가능

```c
if (a > 0)
    printf("it's true!\n");
```

### else 문

- `if` 조건이 false일 때 실행되는 문장을 지정

```c
if (a > 20)
    printf("it's false!\n");
else
    printf("a is less than 20\n");
```

### else if 문

- 여러 조건을 나열할 때 사용, 가장 먼저 만족하는 조건문만 실행됨

```c
if (a > 0)
    printf("it's true!\n");
else if (a >= 10)
    printf("it's also true!\n");
else
    printf("it's false!\n");
```

- `else`는 생략 가능

### 1-1. 중괄호 생략 주의

- 중첩된 `if`에서 `else`는 **가장 가까운 `if`와 연결**
- 명확한 로직 표현을 위해 중괄호 `{}`를 생략하지 않는 것이 좋음

```c
if (a == 0)
    if (b == 20)
        printf("b is 20!!\n");
else
    printf("printf!\n"); // 이 else는 위 if(b==20)과 연결됨
```

---

## **2. switch case 문**

- `if-else if` 구조의 대안으로 사용
- 정수형 표현식을 조건으로 사용하며 `case`로 분기

```c
switch (조건식) {
    case 값1:
        실행문1;
        break;
    case 값2:
        실행문2;
        break;
    default:
        실행문3;
        break;
}
```

### 2-1. 예제

```c
int condition = 2;
int res = 0;

switch (condition) {
    case 1:
        res = 1;
        break;
    case 2:
        res = 2;
        break;
    case 3:
        res = 3;
        break;
    default:
        res = -1;
        break;
}

printf("res is : %d\n", res); // 출력: res is : 2
```

- `case`에 해당하는 조건부터 실행되며, `break`를 만나야 switch문 탈출

### break 생략 시 주의

```c
switch (condition) {
    case 2:
        res += 2;
    case 3:
        res += 3;
    default:
        res += -1;
}
```

- 위 코드에서 `condition == 2`일 경우, `res = 2 + 3 - 1 = 4`

### 2-2. default 위치

- `default`는 필수가 아니며, 위치도 자유
- 해당하는 `case`가 없을 경우 실행

```c
switch (condition) {
    default:
        res += -1;
        break;
    case 1:
        res = 1;
        break;
}
```

---

## 📌 참고 자료

- 열혈 C 프로그래밍
- [C 언어 공식 문서 (MS Learn)](https://learn.microsoft.com/ko-kr/cpp/c-language)
