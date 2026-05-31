[⬅️ 상위 README로 이동](../README.md)

## 📘 C 언어: 변수, 자료형, 입력

## 📌 목차

* [1. 변수](#1-변수)
* [2. 변수의 자료형](#2-변수의-자료형)
* [3. Scanf를 통한 데이터 입력](#3-scanf를-통한-데이터-입력)
* [📌 참고 자료](#-참고-자료)

---

### **1. 변수**

- 데이터를 저장하기 위한 메모리 공간을 확보하려면 변수를 선언해야 함
- 예시:

```c
int a;
```

- `int`: 자료형, `a`: 변수명
- 변수 선언만 하면 **쓰레기값(garbage value)**이 들어감
- 선언 후 대입하거나 동시에 초기화 가능

```c
int a;       // 쓰레기값
a = 10;

int a = 10;  // 선언과 초기화
```

#### 1-1. 변수 선언과 대입 규칙

- 블록 `{}` 안에서 선언한 변수는 해당 블록 내부에서만 사용 가능
- 같은 자료형이면 여러 변수 동시 선언 가능

```c
int a, b, c;
```

- `=` 왼쪽은 변수(저장), 오른쪽은 값(복사 또는 연산 결과)

```c
int a, b;
a = 10;
b = a;
```

---

### **2. 변수의 자료형**

#### 2-1. 정수 자료형

- 크기 순서: `short(2B) → int(4B) → long(4B/8B) → long long(8B)`
- OS에 따라 `long` 크기가 다름 ([MS 공식문서](https://learn.microsoft.com/ko-kr/cpp/cpp/data-type-ranges?view=msvc-170))

#### 2-2. signed vs unsigned

- 기본은 `signed` (부호 있음)
- `unsigned`: 부호 없음 → 양수만 표현

| 자료형 | 범위 |
|--------|------|
| signed int | -2147483648 ~ 2147483647 |
| unsigned int | 0 ~ 4294967295 |

#### 2-3. 실수 자료형

- 크기 순서: `float(4B) → double(8B) → long double(8B 이상)`
- 유효 숫자: float(7자리), double(15자리)

```c
#include <stdio.h>

int main(void) {
    float ft = 1.234567890123456789;
    double db = 1.234567890123456789;

    printf("float형 변수의 값 : %.20f\n", ft);
    printf("double형 변수의 값 : %.20lf\n", db);

    return 0;
}
```

출력 예시:
```
float형 변수의 값 : 1.23456788063049316406
double형 변수의 값 : 1.23456789012345669043
```

- 부동소수점은 **정확하게 표현되지 않을 수 있음**
- 표준: [IEEE 754](https://ko.wikipedia.org/wiki/IEEE_754)

#### 2-4. 문자와 문자열

- `char` 또는 `unsigned char` (1B)
- 문자열: `char[]` 배열 또는 포인터 사용

```c
#include <stdio.h>

int main(void) {
    char fruit[20] = "strawberry";

    printf("딸기 : %s\n", fruit);
    printf("딸기쨈 : %s %s\n", fruit, "jam");

    return 0;
}
```

#### 2-5. const

- 변수의 값을 고정하고 싶을 때 `const` 사용
- 선언과 동시에 초기화 필수

```c
#include <stdio.h>

int main(void) {
    int income = 0;
    double tax;
    const double tax_rate = 0.12;

    income = 456;
    tax = income * tax_rate;
    printf("세금은 %.1lf입니다.\n", tax);

    return 0;
}
```

---

### **3. Scanf를 통한 데이터 입력**

#### 3-1. 사용법과 유의점

- `scanf`는 사용자 입력을 변수에 저장
- 변수 앞에 `&` 필수 (배열은 예외)

```c
int a;
scanf("%d", &a);
```

- 변환 문자와 입력값의 형식이 맞아야 함
- 여러 개 입력도 가능

```c
int a;
double b;
scanf("%d%lf", &a, &b);
```

#### 3-2. 문자/문자열 입력

```c
#include <stdio.h>

int main(void) {
    char grade;
    char name[20];

    printf("학점 입력 : ");
    scanf("%c", &grade);
    printf("이름 입력 : ");
    scanf("%s", name);
    printf("%s의 학점은 %c입니다.\n", name, grade);

    return 0;
}
```

출력 예시:
```
학점 입력 : A
이름 입력 : 김철수
김철수의 학점은 A입니다.
```

- 문자열 입력 시 널문자 `\0` 포함해야 하므로 배열 크기는 여유 있게 선언
- `scanf("%s")`는 공백 전까지만 입력됨 → "김 철수" 입력 시 "김"만 저장됨

---

## 📌 참고 자료

- [MS 자료형 범위 공식 문서](https://learn.microsoft.com/ko-kr/cpp/cpp/data-type-ranges?view=msvc-170)
- [IEEE 754 위키백과](https://ko.wikipedia.org/wiki/IEEE_754)
- 열혈 C 프로그래밍
