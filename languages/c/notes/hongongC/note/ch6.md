[⬅️ 상위 README로 이동](../README.md)

## 📘 C 언어: 반복문과 제어문 정리

## 📌 목차

* [1. while, do while](#1-while-do-while)
* [2. for](#2-for)
* [3. break, continue](#3-break-continue)
* [📌 참고 자료](#-참고-자료)

---

## **1. while, do while**

- 조건이 true인 동안 반복 수행하는 반복문
- `while`: 조건을 먼저 검사 → true일 때 실행  
- `do while`: 일단 한 번 실행한 뒤 조건 검사

### 1-1. while 문

```c
int a = 1;

while (a < 10) {
    a = a * 2;
}

printf("a : %d\n", a); // 출력: 16
```

### 1-2. do while 문

- 최소 1번은 실행해야 할 때 사용

```c
int a = 1;

do {
    a = a * 2;
} while (a < 10);

printf("a : %d\n", a); // 출력: 16
```

- 사용자 입력 보장 예시:

```c
int a;
do {
    scanf("%d", &a);
} while (a < 0);
```

---

## **2. for**

- 구조: `for (초기화; 조건; 반복 후 동작)`
- 가장 많이 사용되는 반복문

```c
int a = 1;

for (int i = 0; i < 3; i++) {
    a = a * 2;
}

printf("a : %d\n", a); // 출력: 8
```

- 초기화/조건/증감 모두 생략 가능 (주의: 무한 루프 가능)
- 블록 내에서 선언한 변수는 블록이 끝나면 소멸됨

---

## **3. break, continue**

### 3-1. break

- 반복문을 즉시 종료
- 가장 가까운 반복문 하나만 탈출

```c
int sum = 0;
for (int i = 1; i <= 10; i++) {
    sum += i;
    if (sum > 30)
        break;
}
printf("sum: %d\n", sum); // 출력: 36
```

- 중첩 반복문의 경우, 안쪽 반복문만 탈출

```c
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("i: %d, j: %d\n", i, j);
        if (j == 1)
            break;
    }
}
```

출력:
```
i: 0, j: 0
i: 0, j: 1
i: 1, j: 0
i: 1, j: 1
i: 2, j: 0
i: 2, j: 1
```

- `switch` 문에서도 `break`는 case 블록 탈출 역할

### 3-2. continue

- 해당 반복 루프를 건너뛰고 다음 반복으로 진행

```c
int sum = 0;

for (int i = 1; i <= 100; i++) {
    if (i % 3 == 0)
        continue;
    sum += i;
}

printf("sum: %d\n", sum); // 3의 배수를 제외한 합
```

---

## 📌 참고 자료

- 열혈 C 프로그래밍
- [C 언어 반복문 공식 문서](https://learn.microsoft.com/ko-kr/cpp/c-language)
