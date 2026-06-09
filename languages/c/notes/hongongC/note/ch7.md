---
created: 2024-03-22
---

[⬅️ 상위 README로 이동](../README.md)

## 📘 함수 (Functions)

## 📌 목차

* [1. 함수 구조](#1-함수-구조)
  * [1-1. 함수 정의](#1-1-함수-정의)
  * [1-2. 함수 호출](#1-2-함수-호출)
  * [1-3. 함수 선언](#1-3-함수-선언)
* [2. 함수 형태](#2-함수-형태)
  * [2-1. 매개변수와 반환에 void](#2-1-매개변수와-반환에-void)
  * [2-2. 재귀함수 이해](#2-2-재귀함수-이해)
* [3. 도전 실전 예제](#3-도전-실전-예제)

---

## **1. 함수 구조**

### **1-1. 함수 정의**

- 함수는 이름, 매개변수, 반환값으로 구성되며 어떤 입력을 받아 어떤 출력을 낼지 결정하는 코드 블록이다.
- 즉, **함수의 이름**, **매개변수(parameter)**, **반환값(return value)** 을 정의한다.

```c
반환형 함수이름(매개변수1, 매개변수2, ...) {
    // 실행할 코드
    return 반환값;
}
```

- 함수 선언부(`반환형 함수이름(...)`)는 함수의 원형(prototype) 또는 시그니처라고 부른다.

---

### **1-2. 함수 호출**

- 함수를 호출(call)하면 해당 함수가 실행되며, 호출 시 전달하는 인자(arguments)는 함수 정의의 매개변수에 대응된다.
- 호출된 함수는 스택(stack) 메모리 공간에 쌓이며, 이 구조를 **콜스택(Call Stack)** 이라고 한다.
- 컴파일 시 `-W` 옵션 등을 설정하면 함수 원형과 다른 호출에 대해 경고나 에러가 발생할 수 있으므로 정확한 시그니처를 사용하는 것이 좋다.

```c
#include <stdio.h>

int sum(int x, int y); // 함수 원형 선언

int main(void) {
    int a = 10, b = 20;
    int result;

    result = sum(a, b); // 함수 호출
    printf("result : %d\n", result); // 30 출력

    return 0;
}

int sum(int x, int y) {
    return x + y;
}
```

- 자료형이 다르더라도 암묵적으로 형변환이 일어나 호출될 수 있다:

```c
#include <stdio.h>

int sum(double x, double y); // float형 인자

int main(void) {
    int a = 10, b = 20;
    int result;

    result = sum(a, b); // 암묵적 형변환
    printf("result : %d\n", result); // 결과는 여전히 30

    return 0;
}

int sum(double x, double y) {
    return x + y;
}
```

---

### **1-3. 함수 선언**

- 함수를 `main()`보다 아래에서 정의하려면, 반드시 상단에 프로토타입 선언을 먼저 해야 컴파일러가 인식할 수 있다.
- 이 선언은 `헤더파일`에 두기도 하며, 큰 프로젝트에서 함수 정의와 선언을 분리하는 것이 일반적이다.

```c
#include <stdio.h>

int sum(int x, int y); // 함수 선언

int main(void) {
    int a = 10, b = 20;
    int result;

    result = sum(a, b);
    printf("result : %d\n", result);

    return 0;
}

int sum(int x, int y) {
    return x + y;
}
```

---

## **2. 함수 형태**

- 함수는 매개변수(parameter)와 반환값(return value)의 유무에 따라 다양한 형태로 정의될 수 있다.

### **2-1. 매개변수와 반환에 void**

- 매개변수가 없고, 반환값도 없을 경우 `void`를 사용한다.
- `void` 함수라도 `return;`을 통해 조기 종료할 수 있다.

```c
#include <stdio.h>

void print_line(void); // 매개변수 없음, 반환값 없음

int main(void) {
    print_line();
    printf("something....\n");
    print_line();
}

void print_line(void) {
    for (int i = 0; i < 50; i++)
        printf("-");
    printf("\n");
}
```

---

### **2-2. 재귀함수 이해**

- 함수 내부에서 자기 자신을 다시 호출하는 함수를 재귀함수(recursive function)라고 한다.
- 함수 호출은 스택에 쌓이므로 종료 조건 없이 재귀를 반복하면 **스택 오버플로우(Stack Overflow)** 가 발생한다.

```c
#include <stdio.h>

void fruit(void);

int main(void) {
    fruit();
    return 0;
}

void fruit(void) {
    printf("apple\n");
    fruit(); // 무한 재귀
}
```

- 위 코드는 `apple`을 무한히 출력하려고 하지만, 결국 메모리 초과로 종료된다.

- `return`은 해당 호출 하나만 종료시킬 뿐이며, 전체 재귀를 종료하려면 종료 조건을 명시해야 한다.

```c
#include <stdio.h>

void fruit(int cnt);

int main(void) {
    fruit(0);
    return 0;
}

void fruit(int cnt) {
    printf("apple\n");
    if (cnt == 2)
        return;
    fruit(cnt + 1);
    printf("jam\n");
}
```

출력:

```
apple
apple
apple
jam
jam
```

---

## **3. 도전 실전 예제**

- 재귀함수를 이용해 1부터 10까지의 합을 구하는 예제

```c
#include <stdio.h>

int rec_func(int n);

int main(void) {
    printf("%d", rec_func(10));
}

int rec_func(int n) {
    if (n == 1)
        return 1;
    return rec_func(n - 1) + n;
}
```
