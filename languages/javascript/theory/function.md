[⬅️ 상위 README로 이동](../README.md)
# 𝒇 함수

## 📌 목차

<!-- til:toc:start -->
- [1. js에서 함수란](#1-js에서-함수란)
- [2. 기본적인 문법](#2-기본적인-문법)
  - [2-1 함수 선언식(Function Declaration)](#2-1-함수-선언식function-declaration)
  - [2-2 함수 표현식(Function Expression)](#2-2-함수-표현식function-expression)
  - [2-3 화살표 함수(Arrow Function)](#2-3-화살표-함수arrow-function)
  - [2-4 즉시 실행 함수(IIFE: Immediately Invoked Function Expression)](#2-4-즉시-실행-함수iife-immediately-invoked-function-expression)
- [3. 객체 생성 함수](#3-객체-생성-함수)
  - [생성자 함수의 특징](#생성자-함수의-특징)
- [4. 객체로서 함수](#4-객체로서-함수)
  - [call과 apply의 차이](#call과-apply의-차이)
  - [bind를 사용한 함수 바인딩](#bind를-사용한-함수-바인딩)
- [관련 개념](#관련-개념)
- [📌 참고 자료](#-참고-자료)
<!-- til:toc:end -->

---

## **1. js에서 함수란**

자바스크립트에서 함수는 **일급 객체(first-class citizen)**로 취급되며, 이는 함수를 변수에 할당하거나, 인자로 전달하거나, 반환값으로 사용할 수 있음을 의미한다.

자바스크립트의 함수는 다음과 같은 특징을 가진다:
- **재사용 가능한 코드 블록**이다.
- **클로저(Closure)를 형성**하여 외부 스코프에 접근할 수 있다.
- **함수 표현식과 함수 선언식**을 통해 정의할 수 있다.
- **익명 함수, 화살표 함수, 즉시 실행 함수(IIFE)** 등 다양한 형태를 가질 수 있다.

```js
function sayHello() {
    console.log("Hello, World!");
}

const greet = function() {
    console.log("Hi!");
};

const arrowGreet = () => console.log("Hey!");
```

---

## **2. 기본적인 문법**

자바스크립트에서 함수를 정의하는 방법에는 여러 가지가 있다.

### **2-1 함수 선언식(Function Declaration)**
```js
function add(a, b) {
    return a + b;
}
```
- `function` 키워드를 사용하여 함수를 선언한다.
- 호이스팅(hoisting)이 적용되어, 함수 선언 이전에도 호출 가능하다.

### **2-2 함수 표현식(Function Expression)**
```js
const subtract = function(a, b) {
    return a - b;
};
```
- 변수에 함수를 할당하는 방식으로, `=` 오른쪽에 익명 함수가 들어간다.
- 호이스팅되지 않기 때문에 선언 이전에 호출할 수 없다.

### **2-3 화살표 함수(Arrow Function)**
```js
const multiply = (a, b) => a * b;
```
- `=>` 문법을 사용하여 간결하게 표현할 수 있다.
- `this`가 바인딩되지 않으며, 일반 함수와 동작 방식이 다를 수 있다.

### **2-4 즉시 실행 함수(IIFE: Immediately Invoked Function Expression)**
```js
(function() {
    console.log("즉시 실행됨");
})();
```
- 정의되자마자 즉시 실행되는 함수이다.
- 전역 변수 오염을 방지할 수 있다.

---

## **3. 객체 생성 함수**

자바스크립트에서는 함수를 이용하여 객체를 생성할 수 있다. 대표적인 방식은 **생성자 함수(Constructor Function)**를 이용하는 것이다.

```js
function Person(name, age) {
    this.name = name;
    this.age = age;
}

const john = new Person("John", 30);
console.log(john.name); // "John"
console.log(john.age);  // 30
```

### **생성자 함수의 특징**
- `new` 키워드를 사용하여 새로운 객체를 생성한다.
- 생성된 객체는 `this`를 통해 프로퍼티를 가진다.
- `prototype`을 활용하여 메서드를 추가할 수 있다.

```js
Person.prototype.greet = function() {
    console.log(`Hello, my name is ${this.name}`);
};

john.greet(); // "Hello, my name is John"
```

---

## **4. 객체로서 함수**

자바스크립트의 함수는 **객체**이므로 프로퍼티를 가질 수 있다.

```js
function example() {}
example.customProp = "This is a function property";

console.log(example.customProp); // "This is a function property"
```

또한, 함수 객체는 `call`, `apply`, `bind` 메서드를 제공하여 실행 컨텍스트를 조작할 수 있다.

### **`call`과 `apply`의 차이**
```js
function greet(message) {
    console.log(`${message}, ${this.name}`);
}

const user = { name: "Alice" };

greet.call(user, "Hello");  // "Hello, Alice"
greet.apply(user, ["Hi"]);  // "Hi, Alice"
```
- `call`: 함수에 `this`를 지정하고, 인수를 개별적으로 전달한다.
- `apply`: 함수에 `this`를 지정하고, 인수를 배열로 전달한다.

### **`bind`를 사용한 함수 바인딩**
```js
const boundGreet = greet.bind(user);
boundGreet("Hey"); // "Hey, Alice"
```
- `bind`는 새로운 함수를 반환하며, `this`가 고정된다.

---

## **관련 개념**

- **클로저(Closure)**: 클로저는 **함수가 선언될 때의 스코프를 기억하는 특성**을 의미한다.

```js
function outerFunction(outerValue) {
    return function innerFunction(innerValue) {
        console.log(`Outer: ${outerValue}, Inner: ${innerValue}`);
    };
}

const closureFunc = outerFunction("outside");
closureFunc("inside"); // "Outer: outside, Inner: inside"
```
   - `innerFunction`은 `outerValue`를 참조할 수 있다.
   - 클로저를 활용하면 **데이터 은닉**이나 **상태 유지**가 가능하다.

</br>

- **호이스팅**: 변수와 함수 선언이 코드 실행 전에 최상단으로 끌어올려지는 JavaScript의 동작 방식
- **실행 컨텍스트**: 코드가 실행될 때 생성되는 환경으로, 변수, 함수, this 등이 저장되고 관리됨
- **일급 객체**: 변수에 할당하거나 인자로 전달할 수 있으며, 반환값으로도 사용 가능한 객체
    - 2급객체나 3급객체는 없다. (필자는 예전에 있는 줄 알았다)
- **스코프**: 변수가 접근할 수 있는 범위를 정의하는 개념으로, 전역 스코프, 함수 스코프, 블록 스코프가 있음

---

## 📌 참고 자료

- [MDN - Functions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions)
- [MDN - Closures](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Closures)
- [MDN - Arrow Functions](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/Arrow_functions)

