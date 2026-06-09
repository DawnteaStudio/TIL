---
created: 2024-03-27
---

[⬅️ 상위 README로 이동](../README.md)

## 📘 개념 정리 템플릿 - 포인터

## 📌 목차

* [1. 포인터 개요](#1-포인터-개요)
* [2. 포인터 활용](#2-포인터-활용)
    * [2-1. 주소와 포인터의 크기](#2-1-주소와-포인터의-크기)
    * [2-2. 포인터 대입](#2-2-포인터-대입)
    * [2-3. call by value, call by reference](#2-3-call-by-value-call-by-reference)
    * [2-4. 상수 포인터와 포인터 상수](#2-4-상수-포인터와-포인터-상수)
* [3. 도전 실전 예제](#3-도전-실전-예제)
* [📌 참고 자료](#-참고-자료)

---

## **1. 포인터 개요**

- 메모리는 데이터를 저장하는 공간이며, 데이터를 사용하려면 해당 메모리의 주소가 필요함
- C는 메모리에 직접 접근 가능한 언어
- 이때 사용하는 개념이 **포인터(pointer)**. 포인터는 메모리 주소를 저장하는 변수

### **1-1. 주소와 주소 연산자 (&)**

- `&`는 주소 연산자로, 변수의 메모리 주소를 반환
- 예:

```c
int a = 10;
printf("%p", &a);  // 변수 a의 주소 출력
```

---

### **1-2. 간접 참조 연산자(*)와 포인터 선언**

- `*`는 간접 참조 연산자이며, 포인터 선언 및 포인터가 가리키는 값을 참조할 때 사용
- 예:

```c
int a = 10;
int *p = &a;        // 포인터 선언 및 주소 할당
printf("%d", *p);   // p가 가리키는 값 출력: 10
```

---

## **2. 포인터 활용**

### **2-1. 주소와 포인터의 크기**

- 포인터의 크기는 운영체제의 주소 길이에 따라 결정
- 64비트 시스템에서는 모든 포인터가 8바이트
- 포인터는 어떤 자료형을 가리키든 크기가 동일하지만, 접근 시 해석 범위가 자료형에 따라 다름

```c
char ch;
int in;
double db;

char *pc = &ch;
int *pi = &in;
double *pd = &db;

printf("%lu\n", sizeof(pc));  // 모두 8
```

---

### **2-2. 포인터 대입**

- 포인터 변수는 자료형에 따라 메모리를 해석하는 방식이 다름
- 잘못된 자료형 포인터 대입은 예측 불가능한 결과를 초래함

```c
int a = 10;
double *pd;
pd = (double *)&a;   // 위험: int의 주소를 double 포인터에 저장
```

---

### **2-3. call by value, call by reference**

- C의 함수 인자는 기본적으로 값이 복사되어 전달 (call by value).
- 포인터를 이용하면 참조 전달(call by reference)이 가능

```c
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int a = 10, b = 20;
swap(&a, &b);  // 참조 전달 → 값 교환됨
```

---

### **2-4. 상수 포인터와 포인터 상수**

- `const int *p`: 포인터가 가리키는 값은 변경 불가 (상수 포인터)
- `int *const p`: 포인터 변수 자체는 변경 불가 (포인터 상수)

```c
const int *p1 = &a;
*p1 = 30;     // ❌
p1 = &b;      // ✅

int *const p2 = &a;
*p2 = 30;     // ✅
p2 = &b;      // ❌
```

---

## **3. 도전 실전 예제**

```c
void swap(double *a, double *b);
void line_up(double *max, double *mid, double *min);

int main() {
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  line_up(&a, &b, &c);
  printf("%.1lf %.1lf %.1lf\n", a, b, c);
}

void swap(double *a, double *b) {
  double tmp = *a;
  *a = *b;
  *b = tmp;
}

void line_up(double *max, double *mid, double *min) {
  if (*mid < *min) swap(mid, min);
  if (*max < *mid) swap(max, mid);
  if (*mid < *min) swap(mid, min);
}
```

---

## 📌 참고 자료

- [C 언어 포인터 정리 - GeeksforGeeks](https://www.geeksforgeeks.org/pointers-in-c/)
- 혼자 공부하는 C 언어 교재
