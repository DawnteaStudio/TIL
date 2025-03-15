## 💻 숫자와 문자

## 📌 목차

- [1. Number](#1-number)
- [2. BigInt](#2-bigint)
- [3. String](#3-string)
- [4. 관련 개념](#4-관련-개념)
- [📌 참고 자료](#-참고-자료)

---

### **1. Number**

자바스크립트에서는 모든 숫자가 `Number` 타입으로 표현되며, 정수와 실수를 별도로 구분하지 않는다. 
이는 **C++이나 Java와의 가장 큰 차이점 중 하나**로, `int`, `float`, `double`과 같은 다양한 숫자 타입이 존재하는 언어들과 달리, 자바스크립트에서는 모든 숫자가 **64비트 부동소수점(IEEE 754) 형식**으로 저장된다.

이로 인해 **정확도 문제**가 발생할 수 있다.

```js
console.log(0.1 + 0.2); // 0.30000000000000004 (부동소수점 오차)
```

---

### **2. BigInt**

`BigInt`는 매우 큰 정수를 다룰 수 있는 자바스크립트의 자료형으로, `Number` 타입과는 다르게 **정확한 정수 연산이 가능**하다.

#### **BigInt의 내부 구조**
`BigInt`는 **가변 크기 정수**를 저장하기 위해 **배열 기반의 다중 정밀도 정수(Multi-Precision Integer) 구조**를 사용한다. 내부적으로 여러 개의 작은 정수(워드, word)로 나뉘어 저장되며, 각 워드는 32비트 또는 64비트 단위로 관리된다.

예를 들어, `123456789012345678901234567890n` 같은 큰 정수를 `BigInt`로 저장하면:

```
BigInt(123456789012345678901234567890n)
↓
[ 0x1B69B4BACD05F15A, 0x4F0D28A1 ]  (가상의 64비트 블록으로 분할)
```

각 블록(워드)은 배열 형태로 관리되며, 연산 시 자리 올림(Carry Propagation) 등의 처리가 필요하다.

#### **BigInt의 연산 방식**
1. **덧셈(Addition)**: 여러 개의 워드를 하나씩 더하면서 자리 올림을 처리한다.
2. **곱셈(Multiplication)**: Karatsuba 곱셈 알고리즘 또는 FFT 기반 곱셈을 사용할 수 있다.
3. **비트 연산(Bitwise Operations) 지원 X**: `BigInt`는 크기가 가변적이므로, `&`, `|`, `^`, `<<`, `>>` 같은 비트 연산자를 사용할 수 없다.

#### **BigInt vs Number**
|  | `Number` (IEEE 754) | `BigInt` |
|----|------------------|----------|
| **최대 크기** | ±1.8 × 10³⁰⁸ | 메모리가 허용하는 한 무제한 |
| **저장 방식** | 64비트 부동소수점 | 배열 기반 다중 정밀도 정수 |
| **정확성** | 큰 정수 연산 시 반올림 오류 발생 | 정확한 정수 연산 가능 |
| **연산 속도** | 빠름 | 느림 (큰 수일수록 성능 저하) |
| **비트 연산 지원** | O | X |

---

### **3. String**

자바스크립트의 문자열은 **변경할 수 없는(immutable) 유니코드 문자들의 시퀀스**다. 
이는 Java나 C++에서의 `String`과 유사하지만, JavaScript에서는 문자열이 원시 값(`primitive`)으로 취급된다.

#### **원시 문자열 vs String 객체**

자바스크립트에서는 문자열이 **원시 값**으로 동작하지만, 메서드를 호출할 때 **임시 String 객체**가 생성되어 메서드를 실행한 후 즉시 삭제된다.

```js
let str = "hello";
console.log(str.toUpperCase()); // "HELLO"
console.log(typeof str); // "string" (여전히 원시 값)
```

반면, `new String("hello")`로 생성하면 **객체**로 취급되어 메서드 실행 후에도 상태가 유지된다.

```js
let objStr = new String("hello");
console.log(typeof objStr); // "object"
console.log(objStr instanceof String); // true
```

하지만, 원시 문자열과 객체 문자열은 다르므로 비교 시 주의해야 한다.

```js
console.log("hello" === new String("hello")); // false (타입이 다름)
```

#### **String 객체 사용을 지양하는 이유**
1. **비효율적인 메모리 사용**: 원시 문자열은 스택(stack)에 저장되지만, `String` 객체는 힙(heap)에 저장되므로 불필요한 메모리 소비가 발생한다.
2. **비교 연산 시 혼란**: 원시 문자열과 객체 문자열을 비교하면 예상치 못한 결과가 나올 수 있다.
3. **문자열 조작 시 비일관성**: `String` 객체에 프로퍼티를 추가할 수 있지만, 문자열 조작 시 유지되지 않는다.

```js
let strObj = new String("hello");
strObj.customProp = "test";
console.log(strObj.customProp); // "test"

let strPrim = "hello";
strPrim.customProp = "test";
console.log(strPrim.customProp); // undefined (원시 값은 프로퍼티를 가질 수 없음)
```

---

### **4. 관련 개념**

#### **원시 문자열의 메모리 구조**
- 원시 문자열은 **스택(stack)에 저장됨** (변경 불가, immutable)
- `new String()`을 사용하면 **힙(heap)에 저장**됨 (객체로 취급됨)
- 문자열을 수정하면 새로운 문자열이 할당되며, 기존 문자열은 GC(가비지 컬렉션)에 의해 정리됨

#### **인터프리터의 문자열 처리 방식**
1. 원시 문자열이 메서드를 호출하면, 자바스크립트 엔진이 자동으로 `new String(str)`을 실행하여 **임시 객체**를 생성한다.
2. 메서드가 실행되고, 결과가 반환된 후 **임시 객체는 즉시 삭제(GC 처리됨)**.

```js
let str = "hello";
str.test = "test"; // 원시 값에 프로퍼티 추가 시도
console.log(str.test); // undefined
```

- 원시 값은 프로퍼티를 추가할 수 없지만, 메서드는 실행 가능한 이유가 여기에 있음.

---

### 📌 참고 자료

- [생활코딩 - 자바스크립트(JavaScript) 기본](https://www.inflearn.com/course/%EC%A7%80%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8-%EC%96%B8%EC%96%B4-%EA%B8%B0%EB%B3%B8)
- [MDN - BigInt (JavaScript)](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/BigInt)
- [MDN - Number (JavaScript)](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Number)
- [MDN - String (JavaScript)](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/String)
