---
created: 2026-08-10
---

# 기본형(Primitive Type) vs 참조형(Reference Type)

## 학습 출처
김영한 java basic

## 개요
자바(Java)에서 데이터를 다루는 방식은 크게 두 가지로 나뉜다. 바로 기본형(Primitive Type)과 참조형(Reference Type) 변수이다. 이 둘의 차이를 명확히 이해하는 것은 자바의 메모리 관리 방식과 객체 지향 프로그래밍의 핵심 개념을 파악하는 데 필수적이다. 본 글에서는 각 변수 타입의 정의와 특징, 그리고 변수 할당 및 메서드 호출 시 동작 방식을 구체적인 예시와 함께 살펴본다.

## 기본형(Primitive Type)의 이해

### 기본형의 정의와 특징
기본형은 자바가 기본적으로 제공하는 데이터 타입으로, 정수, 실수, 문자, 논리값 등 실제 값을 직접 저장하는 특징을 갖는다. 개발자가 새로운 기본형을 직접 정의하는 것은 불가능하며, `byte`, `short`, `int`, `long`, `float`, `double`, `char`, `boolean`과 같이 고정된 여덟 가지 타입만 존재한다. 각 타입은 메모리에 고정된 크기로 값을 저장한다.

### 기본형 변수의 값 저장 방식
기본형 변수를 선언하고 값을 할당하면, 해당 변수에는 실제 데이터 값이 직접 저장된다.

```java
public class PrimitiveTypeExample {
    public static void main(String[] args) {
        int a = 10; // 변수 a에 값 10이 직접 저장된다.
        int b = a;  // 변수 a의 값 10이 복사되어 변수 b에 저장된다.

        System.out.println("a = " + a); // 출력: a = 10
        System.out.println("b = " + b); // 출력: b = 10

        b = 20; // 변수 b의 값을 변경해도 변수 a에는 영향을 미치지 않는다.

        System.out.println("a = " + a); // 출력: a = 10
        System.out.println("b = " + b); // 출력: b = 20
    }
}
```
위 예시에서 `b = a` 코드는 `a`의 값 `10`을 `b`에 복사한다. 이후 `b`의 값을 변경하더라도 `a`의 값은 그대로 유지된다. 이는 두 변수가 각각 독립적인 메모리 공간에 실제 값을 저장하고 있음을 보여준다.

## 참조형(Reference Type)의 이해

### 참조형의 정의와 특징
참조형은 객체(Object)의 메모리 주소, 즉 참조(Reference) 값을 저장하는 데이터 타입이다. 자바에서 클래스(Class), 인터페이스(Interface), 배열(Array), 열거형(Enum) 등 기본형을 제외한 모든 타입은 참조형에 해당한다. 개발자는 클래스를 통해 새로운 참조형을 직접 정의할 수 있으며, 이러한 사용자 정의 클래스는 대문자로 시작하는 것이 업계의 일반적인 관례이다.

### 참조형 변수의 주소 저장 방식
참조형 변수는 실제 데이터(객체 인스턴스)를 직접 저장하지 않고, 해당 객체가 메모리(힙 영역)에 저장된 위치를 가리키는 주소 값을 저장한다.

```java
public class ReferenceTypeExample {
    static class Data { // Data 클래스 정의
        int value;
    }

    public static void main(String[] args) {
        Data dataA = new Data(); // Data 객체를 생성하고 그 주소를 dataA에 저장
        dataA.value = 10;

        Data dataB = dataA;      // dataA가 저장하고 있는 '주소 값'을 dataB에 복사
                                 // 이제 dataA와 dataB는 같은 객체를 가리킨다.

        System.out.println("dataA.value = " + dataA.value); // 출력: dataA.value = 10
        System.out.println("dataB.value = " + dataB.value); // 출력: dataB.value = 10

        dataB.value = 20; // dataB를 통해 가리키는 객체의 값을 변경한다.
                          // dataA와 dataB는 같은 객체를 참조하므로, dataA.value도 변경된다.

        System.out.println("dataA.value = " + dataA.value); // 출력: dataA.value = 20
        System.out.println("dataB.value = " + dataB.value); // 출력: dataB.value = 20
    }
}
```
위 예시에서 `dataB = dataA` 코드는 `dataA`에 저장된 객체의 주소 값을 `dataB`에 복사한다. 결과적으로 `dataA`와 `dataB`는 메모리상에서 동일한 `Data` 객체를 참조하게 된다. 따라서 `dataB.value`를 변경하면 `dataA.value`도 함께 변경된 것처럼 보이는 것은, 두 변수가 동일한 객체의 필드를 조작했기 때문이다.

## 변수 할당 및 메서드 호출 시 동작 방식

자바는 변수를 다른 변수에 대입하거나 메서드 호출 시 매개변수로 전달할 때, 항상 **변수의 값을 복사해서 대입**하는 방식을 사용한다. 이는 C++의 참조(reference) 전달과는 다른 중요한 특징이다.

### 기본형 변수 할당 시 값 복사
기본형 변수의 경우, 실제 값이 복사되어 전달된다.

```java
public class AssignmentExample {
    public static void main(String[] args) {
        int x = 10;
        int y = x; // x의 '값 10'이 복사되어 y에 저장된다.

        System.out.println("초기: x=" + x + ", y=" + y); // x=10, y=10

        y = 20; // y의 값을 변경해도 x에는 영향을 미치지 않는다.

        System.out.println("변경 후: x=" + x + ", y=" + y); // x=10, y=20
    }
}
```
`y = x`는 `x`의 내용물인 `10`이라는 값을 복사하여 `y`에 넣으므로, `x`와 `y`는 완전히 독립적인 값을 갖는다.

### 참조형 변수 할당 시 참조 값 복사
참조형 변수의 경우, 객체의 주소 값(참조 값)이 복사되어 전달된다. 이는 두 변수가 같은 객체를 가리키게 됨을 의미한다.

```java
public class ReferenceAssignmentExample {
    static class ObjectRef {
        int data;
    }

    public static void main(String[] args) {
        ObjectRef obj1 = new ObjectRef();
        obj1.data = 100;

        ObjectRef obj2 = obj1; // obj1이 가진 '객체 주소'가 복사되어 obj2에 저장된다.
                               // 이제 obj1과 obj2는 동일한 ObjectRef 객체를 참조한다.

        System.out.println("초기: obj1.data=" + obj1.data + ", obj2.data=" + obj2.data); // obj1.data=100, obj2.data=100

        obj2.data = 200; // obj2를 통해 객체의 data 필드를 변경하면, obj1으로도 변경된 값을 볼 수 있다.

        System.out.println("변경 후: obj1.data=" + obj1.data + ", obj2.data=" + obj2.data); // obj1.data=200, obj2.data=200
    }
}
```
`obj2 = obj1`은 `obj1` 변수에 저장된 주소 값(객체 참조)을 복사하여 `obj2`에 할당한다. 따라서 `obj1`과 `obj2`는 메모리상의 동일한 `ObjectRef` 객체를 가리키게 된다. 한 변수를 통해 객체의 상태를 변경하면, 다른 변수를 통해서도 변경된 상태를 확인할 수 있다.

### 메서드 호출 시 기본형 매개변수 동작
메서드 호출 시 기본형 매개변수는 값이 복사되어 전달되므로, 메서드 내부에서 매개변수의 값을 변경해도 원본 변수에는 영향을 주지 않는다.

```java
public class PassByValuePrimitive {
    public static void changeValue(int num) {
        System.out.println("  changeValue 메서드 시작: num = " + num); // num = 10
        num = 20; // 메서드 내부의 num 값만 변경된다.
        System.out.println("  changeValue 메서드 종료: num = " + num); // num = 20
    }

    public static void main(String[] args) {
        int value = 10;
        System.out.println("main 메서드 시작: value = " + value); // value = 10
        changeValue(value); // value의 값 10이 num으로 복사되어 전달된다.
        System.out.println("main 메서드 종료: value = " + value); // value = 10 (변화 없음)
    }
}
```
`changeValue` 메서드에 `value`를 전달하면, `value`의 값 `10`이 `num` 매개변수에 복사된다. 메서드 내부에서 `num`을 `20`으로 변경해도 `main` 메서드의 `value` 변수에는 어떠한 영향도 미치지 않는 것을 확인할 수 있다.

### 메서드 호출 시 참조형 매개변수 동작
메서드 호출 시 참조형 매개변수는 객체의 주소 값이 복사되어 전달된다. 이로 인해 메서드 내부에서 해당 주소를 통해 객체의 필드를 변경하면, 메서드 외부의 원본 객체에도 그 변경이 반영된다. 그러나 매개변수 자체에 새로운 객체의 주소를 할당해도 원본 변수에는 영향을 주지 않는다.

```java
public class PassByValueReference {
    static class MyObject {
        int data;
        MyObject(int data) { this.data = data; }
    }

    public static void modifyObject(MyObject obj) {
        System.out.println("  modifyObject 메서드 시작: obj.data = " + obj.data); // obj.data = 100
        obj.data = 200; // obj가 가리키는 객체의 필드를 변경한다.
        System.out.println("  modifyObject 메서드 종료 (필드 변경): obj.data = " + obj.data); // obj.data = 200
    }

    public static void replaceObject(MyObject obj) {
        System.out.println("  replaceObject 메서드 시작: obj.data = " + obj.data); // obj.data = 100 (새로운 객체 생성 전)
        obj = new MyObject(300); // 매개변수 obj에 새로운 객체의 주소를 할당한다.
                                 // 이는 메서드 내부의 'obj' 변수만 새로운 객체를 가리키게 한다.
                                 // 원본 'myObj' 변수에는 영향을 미치지 않는다.
        System.out.println("  replaceObject 메서드 종료 (객체 교체): obj.data = " + obj.data); // obj.data = 300
    }

    public static void main(String[] args) {
        MyObject myObj = new MyObject(100);
        System.out.println("main 메서드 시작: myObj.data = " + myObj.data); // myObj.data = 100

        // 1. 객체의 필드를 변경하는 경우
        modifyObject(myObj); // myObj가 가진 '객체 주소'가 obj로 복사된다.
        System.out.println("main 메서드 종료 후 modifyObject 호출: myObj.data = " + myObj.data); // myObj.data = 200 (변경됨)

        System.out.println("--------------------");

        // 2. 매개변수에 새로운 객체를 할당하는 경우
        myObj = new MyObject(100); // 원본 객체를 초기 상태로 복원
        System.out.println("main 메서드 다시 시작 (객체 교체 전): myObj.data = " + myObj.data); // myObj.data = 100
        replaceObject(myObj); // myObj가 가진 '객체 주소'가 obj로 복사된다.
        System.out.println("main 메서드 종료 후 replaceObject 호출: myObj.data = " + myObj.data); // myObj.data = 100 (변화 없음)
    }
}
```
`modifyObject` 메서드에 `myObj`를 전달하면, `myObj`가 저장하고 있는 객체의 주소 값이 `obj` 매개변수에 복사된다. 따라서 `obj`와 `myObj`는 동일한 객체를 가리키게 되며, `obj.data = 200`을 통해 객체의 `data` 필드를 변경하면 `main` 메서드에서도 변경된 값을 확인할 수 있다.

반면 `replaceObject` 메서드에서 `obj = new MyObject(300)`과 같이 매개변수 `obj`에 새로운 객체를 할당하는 것은 `main` 메서드의 `myObj` 변수에는 영향을 주지 않는다. 이는 `obj`라는 지역 변수에 새로운 주소 값을 할당하는 것일 뿐, `myObj`에 복사된 원래 주소 값 자체를 변경하는 것이 아니기 때문이다. `myObj`는 여전히 처음에 참조하던 객체를 가리킨다.

## 멤버 변수와 지역 변수

변수는 선언되는 위치에 따라 멤버 변수와 지역 변수로 구분되며, 각각 다른 특징과 초기화 규칙을 갖는다.

### 멤버 변수 (Member Variable)
멤버 변수는 클래스 내부에 선언되는 변수이다. 이러한 변수는 객체의 상태를 나타내며, `필드(Field)`라고도 불린다. 멤버 변수는 클래스 인스턴스화 시점에 생성되며, 개발자가 명시적으로 초기화하지 않아도 자바 컴파일러가 해당 변수의 타입에 맞는 기본값으로 자동으로 초기화한다.

*   **숫자 타입**: 0
*   **boolean 타입**: false
*   **참조 타입**: null

```java
public class MemberVariableExample {
    int memberInt;         // int형 멤버 변수, 0으로 자동 초기화
    boolean memberBoolean; // boolean형 멤버 변수, false로 자동 초기화
    String memberString;   // String형 멤버 변수, null로 자동 초기화

    public static void main(String[] args) {
        MemberVariableExample instance = new MemberVariableExample();

        System.out.println("memberInt: " + instance.memberInt);       // 출력: 0
        System.out.println("memberBoolean: " + instance.memberBoolean); // 출력: false
        System.out.println("memberString: " + instance.memberString);   // 출력: null
    }
}
```

### 지역 변수 (Local Variable)
지역 변수는 메서드, 생성자, 또는 코드 블록 내부에 선언되는 변수이다. 이 변수들은 선언된 블록 내에서만 유효하며, 해당 블록이 종료되면 메모리에서 사라진다. 지역 변수는 멤버 변수와 달리 개발자가 명시적으로 초기화해야 하며, 초기화하지 않고 사용하려고 하면 컴파일 오류가 발생한다. 매개변수(parameter) 또한 메서드 내부에서만 사용되는 지역 변수의 일종으로 간주된다.

```java
public class LocalVariableExample {
    public void myMethod() {
        int localInt; // 지역 변수 선언

        // System.out.println(localInt); // 컴파일 오류: localInt가 초기화되지 않았다.

        localInt = 10; // 초기화 후 사용 가능
        System.out.println("localInt: " + localInt); // 출력: 10
    }

    public void anotherMethod(int parameterInt) { // parameterInt는 지역 변수
        System.out.println("parameterInt: " + parameterInt); // 매개변수는 호출 시 값이 할당되므로 초기화 불필요
    }

    public static void main(String[] args) {
        LocalVariableExample example = new LocalVariableExample();
        example.myMethod();
        example.anotherMethod(20);
    }
}
```
`myMethod` 내부의 `localInt`는 초기화 없이 사용하려 하면 컴파일 오류가 발생한다. 이는 자바가 지역 변수의 사용 전 초기화를 강제하여 잠재적인 런타임 오류를 방지하려는 의도이다. 반면 `anotherMethod`의 `parameterInt`는 메서드 호출 시 값이 전달되므로 별도의 초기화 없이 바로 사용 가능하다.

## 현재 이해한 결론

자바에서 기본형과 참조형 변수는 데이터를 다루는 방식에서 근본적인 차이를 보인다.

*   **기본형(Primitive Type)**: 변수에 실제 데이터 값을 직접 저장한다. `int`, `boolean` 등이 이에 해당하며, 값의 크기가 고정되어 있다. 변수를 대입하거나 메서드에 전달할 때 항상 값이 복사된다. 즉, 독립적인 두 변수가 각각의 메모리 공간에 동일한 값을 갖게 된다.
*   **참조형(Reference Type)**: 변수에 객체의 메모리 주소(참조 값)를 저장한다. 클래스, 배열 등이 이에 해당하며, 실제 객체는 힙(Heap) 영역에 생성된다. 변수를 대입하거나 메서드에 전달할 때 객체의 '주소 값'이 복사된다. 이로 인해 여러 참조 변수가 하나의 객체를 가리킬 수 있으며, 한 변수를 통해 객체의 상태를 변경하면 해당 객체를 참조하는 다른 모든 변수에도 그 변경이 반영된다. 다만, 매개변수 자체에 새로운 객체 주소를 할당하는 것은 원본 참조 변수에 영향을 주지 않는다.

또한, 변수의 선언 위치에 따라 동작 방식에 차이가 있다.

*   **멤버 변수**: 클래스 내부에 선언되며, 객체의 필드로 사용된다. 명시적으로 초기화하지 않아도 자바가 기본값으로 자동 초기화한다.
*   **지역 변수**: 메서드나 블록 내부에 선언되며, 해당 스코프 내에서만 유효하다. 사용 전에 반드시 개발자가 명시적으로 초기화해야 하며, 그렇지 않으면 컴파일 오류가 발생한다. 매개변수도 지역 변수의 일종이다.

이러한 기본형과 참조형, 그리고 멤버 변수와 지역 변수의 특징을 정확히 이해하는 것은 자바 애플리케이션의 메모리 관리, 객체 상태 변화, 그리고 오류 없는 코드 작성에 필수적인 지식이다.