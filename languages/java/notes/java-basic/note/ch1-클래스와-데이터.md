---
created: 2026-06-17
---

# Java 클래스와 데이터: 객체, 인스턴스, 그리고 접근 제어자 파헤치기

이번 학습 일지에서는 자바 클래스와 데이터의 기본적인 개념들을 다시 한번 짚어보고, 특히 처음엔 좀 헷갈렸던 객체와 인스턴스의 차이, 그리고 접근 제어자 중 `default`와 `private`의 미묘하지만 중요한 차이에 대해 깊이 이해한 내용을 정리해 보려고 한다.

## 학습 출처
클래스와 데이터 관련 학습 자료들을 참고했다.

## 오늘 배운 것

자바의 클래스와 데이터를 다루면서 몇 가지 핵심적인 규칙과 개념들을 다시 한번 되새겼다. 특히 자바의 엄격한 구조와 그것을 제어하는 접근 제어자의 역할에 대해 다시 생각해보는 계기가 됐다.

### 1. 자바의 Public 클래스는 파일에 하나만 존재해야 한다

자바는 소스 코드(.java 파일) 내에 `public` 클래스는 단 하나만 존재하도록 강제한다. 그리고 이 `public` 클래스의 이름은 반드시 파일 이름과 같아야 한다. 만약 이 규칙을 어기면 컴파일 시 오류가 발생한다.

**왜 이런 규칙이 있을까?**
이는 자바의 클래스 로딩 시스템과 밀접한 관련이 있다. JVM이 클래스를 찾을 때, 파일 이름과 `public` 클래스 이름이 일치해야 예상대로 클래스를 로드할 수 있다. 이는 프로젝트의 구조를 명확하게 하고, 여러 개발자가 협업할 때 혼란을 줄이는 중요한 규칙이다.

```java
// MyClass.java 파일 안에 있다고 가정
public class MyClass { // 이 클래스는 파일 이름과 일치
    public static void main(String[] args) {
        System.out.println("Hello from MyClass!");
    }
}

// 이 클래스는 public이지만 MyClass.java 파일 안에 함께 있으면 컴파일 오류가 발생한다.
// class AnotherClass { // 이렇게 public이 아니면 한 파일에 여러 클래스를 선언할 수 있다.
//     void doSomething() {
//         System.out.println("Doing something...");
//     }
// }
```

만약 `public class AnotherClass`를 `MyClass.java` 파일 안에 선언한다면, 컴파일러는 `class AnotherClass is public, should be declared in a file named AnotherClass.java`와 같은 오류 메시지를 보여줄 것이다.

### 2. 자바의 4가지 접근 제어자

자바는 클래스, 필드(변수), 메서드, 생성자에 대한 접근 범위를 제어하기 위해 4가지 접근 제어자(Access Modifier)를 제공한다. 이 제어자들을 통해 코드의 캡슐화를 강화하고, 불필요한 외부 노출을 막아 안정성을 높일 수 있다.

*   **`public` (가장 개방적):** 어디서든 접근할 수 있다. 말 그대로 '전 세계'에 공개된다.
*   **`protected`:** 같은 패키지 내의 클래스들과, 다른 패키지에 있더라도 이 클래스를 상속받은 자식 클래스에서 접근할 수 있다.
*   **`default` (아무것도 안 붙임, package-private):** 아무런 접근 제어자를 명시하지 않으면 `default` 접근 제어가 적용된다. 이 경우 같은 패키지 내의 클래스에서만 접근할 수 있다. 외부 패키지에서는 접근할 수 없다.
*   **`private` (가장 폐쇄적):** 해당 클래스 내부에서만 접근할 수 있다. 외부에서는 절대 접근할 수 없다.

이 접근 제어자들의 이해는 특히 `default`와 `private`의 차이를 명확히 구분하는 데 중요했다.

## 헷갈린 점

학습 과정에서 특히 두 가지 개념이 명확하게 와닿지 않아 혼란스러웠다.

*   **객체와 인스턴스 차이:** 둘 다 메모리 상에 존재하는 어떤 '실체'를 지칭하는 것 같아서 정확히 어떤 뉘앙스 차이가 있는지 헷갈렸다.
*   **`default` (아무것도 안 붙임)와 `private`의 차이:** `default`가 같은 패키지만 공개하고 `private`는 나 혼자만 사용한다는 설명이 있었는데, 이게 실제 코드에서 어떤 차이를 만들고 왜 분리된 개념으로 존재하는지 명확하게 구분하기 어려웠다. C++에서는 `private`가 클래스 내부에서만 접근 가능하고, 별도의 패키지 개념이 없으니 `default` 같은 게 존재하지 않아 더욱 헷갈렸다.

## 현재 이해한 결론

헷갈렸던 점들을 다시 한번 생각하고 여러 자료를 찾아보며, 이제는 명확하게 개념을 구분할 수 있게 되었다.

### 1. 객체와 인스턴스의 차이점: '관계'에 주목하기

객체(Object)와 인스턴스(Instance)는 사실상 같은 것을 지칭하는 경우가 많아 혼용되기도 하지만, 정확히는 **'관계'에 초점을 맞출 때 인스턴스라는 용어가 더 적합하다**는 것을 알게 됐다.

*   **객체 (Object):**
    *   클래스에서 정의한 속성(변수)과 기능(메서드)을 가진 **실체**를 통칭하는 광범위한 용어다.
    *   프로그램에서 생성되는 모든 것(변수, 함수, 데이터 구조 등)을 객체라고 부를 수 있다.
    *   예를 들어, "자동차는 객체다", "사람은 객체다"와 같이 어떤 종류의 '실체'가 존재한다는 일반적인 사실을 말할 때 사용한다.

*   **인스턴스 (Instance):**
    *   특정 클래스로부터 **생성된(instantiated) 구체적인 객체**를 지칭할 때 사용한다.
    *   "~의 인스턴스"라고 표현함으로써, 어떤 클래스와의 관계를 명확히 한다.
    *   클래스는 '설계도' 또는 '틀'이고, 인스턴스는 그 설계도를 바탕으로 '만들어진 실제 물건'에 가깝다.

**예시로 이해하기:**

`Student` 클래스가 있다고 가정해 보자. 이 `Student` 클래스는 학생의 이름, 학번 등의 속성과 공부하기, 시험 보기 같은 기능을 정의하는 '설계도'다.

```java
// Student.java
class Student {
    String name;
    String studentId;

    public Student(String name, String studentId) {
        this.name = name;
        this.studentId = studentId;
    }

    void study() {
        System.out.println(name + "이(가) 공부합니다.");
    }
}
```

이제 이 `Student` 클래스를 이용해 실제 학생들을 만들어보자.

```java
// Main.java
public class Main {
    public static void main(String[] args) {
        Student student1 = new Student("김철수", "20230001");
        Student student2 = new Student("박영희", "20230002");

        student1.study(); // 김철수가 공부합니다.
        student2.study(); // 박영희가 공부합니다.
    }
}
```

여기서 `student1`과 `student2`는 메모리에 실제로 생성된 `Student` 타입의 데이터 덩어리다.

*   우리는 `student1`과 `student2`를 통틀어 **'객체'**라고 부를 수 있다.
*   하지만 `student1`은 "Student 클래스의 **인스턴스**이다", `student2`도 "Student 클래스의 **인스턴스**이다"라고 표현하는 것이 더 정확하고 자연스럽다.

**정리하자면:** `인스턴스`는 **특정 클래스의 구체적인 객체**를 의미하며, 클래스와 객체 간의 **생성 관계**를 명확히 보여주는 용어다. "객체"는 더 일반적인 개념이며, "인스턴스"는 "특정 클래스의 객체"라는 좀 더 구체적인 의미를 가진다. 그래서 `student1`은 `Student` 클래스의 객체이면서, 동시에 `Student` 클래스의 인스턴스인 것이다. `인스턴스(instance)`라는 단어 자체도 '구체적인 사례, 예시'라는 의미를 가지며, 클래스라는 '청사진'의 구체적인 '실체'를 의미하는 데 적절하다.

### 2. `default`와 `private` 접근 제어자의 명확한 구분: '패키지'의 중요성

`default` 접근 제어자(아무것도 명시하지 않은 경우)와 `private` 접근 제어자의 차이는 자바의 **패키지(package)** 개념을 이해하면 명확해진다. C++ 같은 언어에서는 `private`이 클래스 내부에만 접근을 허용하고, `default`와 같은 개념이 직접적으로 없어 헷갈리기 쉬웠던 부분이다.

**`private`:**
*   가장 엄격한 접근 제어자로, **오직 해당 클래스 내부**에서만 접근이 가능하다.
*   같은 클래스 내의 다른 메서드나 생성자에서만 이 멤버를 사용할 수 있다.
*   **외부 클래스(심지어 같은 패키지에 있더라도)는 절대 접근할 수 없다.**
*   캡슐화를 실현하는 핵심적인 제어자로, 객체의 내부 상태를 보호하고 외부에서 직접 변경하는 것을 막아 데이터의 무결성을 유지하는 데 사용한다.

**`default` (package-private):**
*   **같은 패키지 내부**에 있는 모든 클래스에서 접근할 수 있다.
*   하지만 **다른 패키지**에 있는 클래스에서는 접근할 수 없다.
*   `package-private`이라는 별칭이 이 접근 제어자의 역할을 가장 잘 설명해준다. 마치 한 패키지라는 '가족' 안에서는 모두가 공유하지만, 다른 패패키지라는 '외부인'에게는 숨겨지는 것과 같다.
*   자바는 `default` 접근 제어자를 통해 같은 패키지 내의 클래스들 간에는 유연하게 협력할 수 있도록 하면서도, 패키지 외부로부터는 내부 구현을 숨길 수 있도록 한다.

**예시로 차이점 이해하기:**

다음과 같은 파일 구조와 코드가 있다고 가정해 보자.

```
src/
├── com/
│   └── example/
│       └── model/
│           ├── Account.java
│           └── User.java
│
└── com/
    └── example/
        └── app/
            └── BankApp.java
```

**`Account.java` (com.example.model 패키지)**

```java
package com.example.model;

public class Account {
    private String accountNumber; // private: 이 클래스 내에서만 접근 가능
    String ownerName;             // default: 같은 패키지(com.example.model) 내에서만 접근 가능
    protected double balance;     // protected: 같은 패키지 또는 상속받은 클래스에서 접근 가능

    public Account(String accountNumber, String ownerName, double balance) {
        this.accountNumber = accountNumber;
        this.ownerName = ownerName;
        this.balance = balance;
    }

    // private 멤버는 public 메서드를 통해 간접적으로 접근
    public String getAccountNumber() {
        return accountNumber;
    }

    void deposit(double amount) { // default: 같은 패키지 내에서만 호출 가능
        if (amount > 0) {
            this.balance += amount;
            System.out.println(ownerName + "님의 계좌에 " + amount + "원 입금. 잔액: " + balance);
        }
    }
}
```

**`User.java` (com.example.model 패키지)**

```java
package com.example.model;

// 같은 패키지(com.example.model) 내의 다른 클래스
public class User {
    public static void main(String[] args) {
        Account myAccount = new Account("123-456", "김철수", 1000.0);

        // 1. private 멤버 (accountNumber) 접근 시도 -> 컴파일 오류!
        // System.out.println(myAccount.accountNumber); // 에러: accountNumber는 private 접근을 가집니다.

        // 2. default 멤버 (ownerName) 접근 시도 -> 성공! (같은 패키지이므로)
        System.out.println("계좌 소유자 (default): " + myAccount.ownerName); // 출력: 김철수

        // 3. default 메서드 (deposit) 호출 시도 -> 성공! (같은 패키지이므로)
        myAccount.deposit(500); // 출력: 김철수님의 계좌에 500.0원 입금. 잔액: 1500.0

        // 4. protected 멤버 (balance) 접근 시도 -> 성공! (같은 패키지이므로)
        System.out.println("현재 잔액 (protected): " + myAccount.balance); // 출력: 1500.0
    }
}
```

**`BankApp.java` (com.example.app 패키지 - 다른 패키지)**

```java
package com.example.app;

import com.example.model.Account; // 다른 패키지의 Account 클래스를 사용하려면 import 해야 한다.

public class BankApp {
    public static void main(String[] args) {
        Account yourAccount = new Account("789-012", "박영희", 2000.0);

        // 1. private 멤버 (accountNumber) 접근 시도 -> 컴파일 오류!
        // System.out.println(yourAccount.accountNumber); // 에러: accountNumber는 private 접근을 가집니다.

        // 2. default 멤버 (ownerName) 접근 시도 -> 컴파일 오류! (다른 패키지이므로)
        // System.out.println(yourAccount.ownerName); // 에러: ownerName은 com.example.model.Account에서 default 접근을 가집니다.

        // 3. default 메서드 (deposit) 호출 시도 -> 컴파일 오류! (다른 패키지이므로)
        // yourAccount.deposit(300); // 에러: deposit(double)은 com.example.model.Account에서 default 접근을 가집니다.

        // 4. protected 멤버 (balance) 접근 시도 -> 컴파일 오류! (다른 패키지이므로 상속 없이는 접근 불가)
        // System.out.println(yourAccount.balance); // 에러: balance는 com.example.model.Account에서 protected 접근을 가집니다.

        // public 메서드를 통한 접근은 언제나 가능
        System.out.println("계좌 번호 (public 메서드): " + yourAccount.getAccountNumber()); // 출력: 789-012
    }
}
```

이 예시를 통해 `private`는 클래스 외부에서는 아예 접근이 불가능하며, `default`는 같은 패키지 내에서는 자유롭게 접근할 수 있지만 다른 패키지에서는 `private`처럼 접근이 제한된다는 것을 명확히 이해할 수 있었다. C++에서 `private`가 클래스 외부 접근을 막는 것과 유사하게, 자바의 `default`는 패키지 외부 접근을 막는 역할이라고 보면 된다. 덕분에 각 멤버를 어떤 범위까지 노출할지 정교하게 제어할 수 있는 자바의 강점을 실감하게 됐다.