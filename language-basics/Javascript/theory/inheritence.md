[⬅️ 상위 README로 이동](../README.md)
## 📦 JavaScript에서 상속(Inheritance) 구조

## 📌 목차

- [1. 개요](#1-개요)
- [2. 상속의 목적과 개념](#2-상속의-목적과-개념)
- [3. 프로토타입 기반 상속의 원리](#3-프로토타입-기반-상속의-원리)
- [4. 생성자 함수 상속 구현 방식](#4-생성자-함수-상속-구현-방식)
- [5. instanceof 연산자 동작 원리](#5-instanceof-연산자-동작-원리)
- [6. ES6 클래스 상속과 차이점](#6-es6-클래스-상속과-차이점)
- [📌 참고 자료](#-참고-자료)

---

### **1. 개요**

- JavaScript는 **클래스 기반 상속**이 아닌 **프로토타입 기반 상속**을 사용한다.
- 객체는 자신의 프로퍼티에 없으면 **__proto__** 를 따라 부모의 프로퍼티를 탐색한다.
- 함수의 `prototype`과 인스턴스의 `__proto__`를 연결함으로써 상속 구조가 형성된다.

---

### **2. 상속의 목적과 개념**

- **공통된 속성 및 메서드를 재사용**하여 객체 간 중복 제거
- 하위 객체가 상위 객체의 메서드 및 속성에 접근할 수 있도록 **상속 체계**를 만든다
- JavaScript에서는 `__proto__` 체인을 통해 메서드를 찾아간다

---

### **3. 프로토타입 기반 상속의 원리**

```javascript
function Person(name) {
  this.name = name;
}

Person.prototype.introduce = function () {
  return "My name is " + this.name;
};

function Programmer(name, language) {
  Person.call(this, name); // 상위 생성자 호출 (super)
  this.language = language;
}

Programmer.prototype = Object.create(Person.prototype); // 핵심: 상속 연결
Programmer.prototype.constructor = Programmer; // 생성자 재설정

Programmer.prototype.code = function () {
  return this.name + " codes in " + this.language;
};

const p = new Programmer("Eve", "JavaScript");
console.log(p.introduce()); // "My name is Eve"
console.log(p.code()); // "Eve codes in JavaScript"
```

✅ **부연설명**:

- `Person.call(this, name)` → `Person` 생성자의 초기화 코드를 현재 `this`(Programmer 인스턴스)에 실행시켜 인스턴스 프로퍼티인 `name`을 복사한다. 이는 ES6의 `super(name)`과 같은 역할을 한다.

- `Programmer.prototype = Object.create(Person.prototype)` → `Programmer.prototype`을 새로 만들되, `Person.prototype`을 그 객체의 `__proto__`로 설정한다. 이 구조를 통해 `introduce()` 같은 메서드가 상속되며, 내부적으로는 다음과 같은 객체 관계가 형성된다:

```
Programmer.prototype
  └── __proto__ → Person.prototype
```

- `Programmer.prototype.constructor = Programmer` → 위에서 `Programmer.prototype`을 덮었기 때문에 기본으로 있던 `.constructor` 속성이 `Person`을 가리키게 된다. 이를 다시 `Programmer`로 정확히 되돌려 주는 것. 기능적으로는 없어도 동작하지만, 디버깅, 타입 판별, 코드 추적 측면에서 필수적인 관례이다.

🧱 Object.create 내부 구현 시뮬레이션:

```javascript
function create(proto) {
  function F() {}
  F.prototype = proto;
  return new F();
}
```

📌 위 코드는 `Object.create(proto)`가 하는 동작과 같으며, 생성자 없이 `__proto__`만 연결된 객체를 만드는 방식이다.

✅ 핵심은 `Programmer.prototype`이 `Person.prototype`을 **참조**하도록 연결하는 것이다.

---

### **4. 생성자 함수 상속 구현 방식**

1. **부모 생성자 함수 호출**: `Person.call(this, ...)`
2. **프로토타입 연결**: `Programmer.prototype = Object.create(Person.prototype)`
3. **constructor 재지정**: `Programmer.prototype.constructor = Programmer`

```plaintext
p (new Programmer)
  └─ __proto__ → Programmer.prototype
                       └─ __proto__ → Person.prototype
                                            └─ __proto__ → Object.prototype
```

✅ 위 체인을 통해 `introduce()`는 Person에서, `code()`는 Programmer에서 찾을 수 있다.

---

### **5. instanceof 연산자 동작 원리**

- `a instanceof B`는 `a.__proto__`, `a.__proto__.__proto__` ... 를 따라가며
  `B.prototype`과 일치하는지 확인한다

```javascript
p instanceof Programmer; // true
p instanceof Person;     // true
p instanceof Object;     // true
```

✅ 이유: `p.__proto__` → `Programmer.prototype` → `Person.prototype` → `Object.prototype`

---

### **6. ES6 클래스 상속과 차이점**

```javascript
class Person {
  constructor(name) {
    this.name = name;
  }

  introduce() {
    return `My name is ${this.name}`;
  }
}

class Programmer extends Person {
  constructor(name, language) {
    super(name);
    this.language = language;
  }

  code() {
    return `${this.name} codes in ${this.language}`;
  }
}

const dev = new Programmer("Bob", "Python");
console.log(dev.introduce());
console.log(dev.code());
```

✅ ES6에서는 `extends`, `super()` 키워드를 사용하여 명시적으로 상속 구조를 작성할 수 있다
✅ 내부적으로는 여전히 프로토타입 체인으로 연결된다 (syntactic sugar)

```plaintext
dev
  └─ __proto__ → Programmer.prototype
                       └─ __proto__ → Person.prototype
                                            └─ __proto__ → Object.prototype
```

---

### 📌 참고 자료

- [MDN - Inheritance and the prototype chain](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Inheritance_and_the_prototype_chain)
- [JavaScript Info - Prototype inheritance](https://javascript.info/prototype-inheritance)
- [Understanding ES6 inheritance - Exploring ES6](https://exploringjs.com/es6/ch_classes.html)

---

> ✨ **최종 요약**
>
> **자바스크립트 상속은 객체 간의 `__proto__` 링크를 통해 구현된다. 생성자 함수든 클래스 문법이든, 핵심은 인스턴스의 `__proto__`가 부모의 `prototype`을 가리키도록 연결하는 것이다. 이를 통해 상속, 오버라이딩, instanceof 등 모든 상속 관련 기능이 동작한다.**