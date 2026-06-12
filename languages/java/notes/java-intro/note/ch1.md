---
created: 2026-06-12
---

# Java의 첫걸음: 명세, 구현, 그리고 컴파일부터 실행까지의 여정

2026년 6월 12일

자바를 처음 배우는 과정에서, 단순히 코드를 작성하고 실행하는 것을 넘어 그 내부 원리를 이해하는 것은 정말 중요한 것 같아. 오늘은 자바가 어떻게 구성되어 있고, 우리가 작성한 코드가 실제로 어떻게 기계어로 번역되고 실행되는지에 대한 기본적인 과정을 깊이 들여다보는 시간을 가졌어. 특히 인텔리제이 같은 통합 개발 환경(IDE)이 이 복잡한 과정을 얼마나 편리하게 만들어주는지 이해하는 계기가 되었지.

## 학습 출처
김영한 자바 입문 1강 hello_world

## 오늘 배운 것

오늘 자바의 기초를 다지면서 몇 가지 중요한 개념을 익혔어.

나는 자바가 단순히 하나의 언어가 아니라, '표준 스펙'과 이를 구현한 '실제 시스템'으로 나뉜다는 것을 알게 되었어. 이는 마치 건축 설계도와 실제 건물이 다르듯이, 자바 언어의 규칙과 이를 실제로 동작하게 하는 엔진이 따로 존재한다는 의미였지.

우리가 작성한 자바 소스 코드가 컴퓨터에서 실행되기까지는 두 단계를 거친다는 것도 배웠어. 바로 '컴파일' 단계와 '실행' 단계 말이야.

`javac`라는 도구를 사용해서 자바 소스 파일(`.java`)을 컴파일하면, 컴퓨터가 이해할 수 있는 형태의 중간 코드인 '바이트코드' 파일(`.class`)이 만들어진다는 것을 이해했어. 그리고 이 바이트코드 파일을 `java`라는 명령어로 실행하면 비로소 우리가 만든 프로그램이 동작하는 거야.

특히 인텔리제이와 같은 IDE가 이 모든 과정을 얼마나 편리하게 해주는지 직접 느꼈어. 내가 코드를 작성하고 실행 버튼을 누르면, IDE가 내부적으로 `javac` 명령어를 이용해 관련된 모든 파일을 컴파일하고, 이어서 `java` 명령어로 컴파일된 메인 클래스를 실행해 준다는 사실이 흥미로웠어. 마치 복잡한 지휘를 IDE가 알아서 척척 해주는 느낌이었지.

## 헷갈린 점

자바의 기본 동작 원리를 배우면서 몇 가지 궁금증이 생겼어.

*   자바는 '표준 스펙'과 '구현'으로 나뉜다고 했는데, 이 둘이 정확히 무엇을 의미하고 어떤 구성 요소로 이루어져 있는지 명확하게 다가오지 않았어. 'JDK', 'JRE', 'JVM' 같은 용어들이 각각 어떤 역할을 하는지 헷갈렸지.
*   소스 파일(`.java`)을 컴파일하면 `.class` 파일이 생긴다고 들었어. 그런데 여러 개의 자바 파일(예: `A.java`, `B.java`)이 있을 때 `javac` 명령어가 정확히 어떻게 작동하는지 궁금했어. `javac A.java B.java`처럼 일일이 다 써야 하는 건지, 아니면 다른 더 편리한 방식이 있는 건지 궁금했어.
*   컴파일된 파일을 실행할 때는 `java [컴파일된 파일]` 형태로 쓴다고 하는데, 여기서 말하는 '[컴파일된 파일]'이 정확히 어떤 파일이고, 어떤 규칙으로 이름을 붙여 실행하는지 헷갈렸어. 소스 파일 이름 그대로 쓰는 건지, 아니면 `.class` 확장자를 붙여야 하는 건지 궁금했어.
*   인텔리제이 같은 IDE가 이 모든 과정을 자동으로 해준다고 하는데, 구체적으로 어떤 명령어를 어떤 순서로 실행해서 나에게는 하나의 버튼 클릭으로 보이는지 궁금했어.

## 현재 이해한 결론

헷갈렸던 점들을 하나씩 짚어가며 자바의 기본적인 작동 방식에 대해 더 깊이 이해할 수 있었어.

### 자바의 표준 스펙과 구현: JDK, JRE, JVM의 역할

처음에는 자바가 '표준 스펙'과 이를 '구현'한 것으로 나뉜다는 개념이 다소 추상적으로 느껴졌어. 하지만 이는 자바 생태계를 이해하는 데 매우 중요한 기본 개념이었지.

*   **자바 표준 스펙 (Java Specification)**: 자바 언어가 어떤 문법을 가져야 하고, 어떤 기능을 제공해야 하며, 각 기능이 어떻게 동작해야 하는지 정의해 놓은 설계도 같은 것이야. 예를 들어, `int` 변수는 몇 비트여야 하고, `for` 루프는 어떻게 동작해야 하는지 등의 약속들이 여기에 담겨 있지. 이 스펙은 'JCP(Java Community Process)'라는 곳에서 관리하며, `Java SE Specification` 같은 이름으로 발표돼.
*   **자바 구현 (Java Implementation)**: 이 스펙을 실제 컴퓨터에서 동작하도록 만든 소프트웨어 묶음을 말해. 오라클(Oracle)이 만든 'OpenJDK'나 'Oracle JDK'가 대표적인 구현체들이야. 이 구현체들은 다시 여러 구성 요소로 나뉘는데, 우리가 자주 듣는 'JDK', 'JRE', 'JVM'이 바로 그것들이야.

이 세 가지 용어의 약자를 살펴보면 그 역할을 더 명확하게 알 수 있었어.

*   **JVM (Java Virtual Machine)**: '자바 가상 머신'이라는 뜻으로, 이름 그대로 자바 프로그램을 실행하기 위한 가상의 컴퓨터 환경이야. `javac`로 컴파일된 `.class` 파일(바이트코드)을 읽어서 운영체제에 맞게 해석하고 실행해 주는 핵심 엔진이지. 자바가 "한 번 작성하면 어디서든 실행된다(Write Once, Run Anywhere)"는 구호를 가질 수 있었던 것도 JVM 덕분이야. 각 운영체제(Windows, macOS, Linux)마다 해당 운영체제에 맞는 JVM이 있어서, 개발자는 특정 OS에 종속되지 않고 자바 코드를 작성할 수 있어.
*   **JRE (Java Runtime Environment)**: '자바 런타임 환경'을 의미해. JVM에 자바 코드를 실행하는 데 필요한 라이브러리 파일들을 묶어 놓은 패키지야. 자바 프로그램을 *실행만* 하려는 사용자에게 필요한 최소한의 환경을 제공해 줘. JRE 안에는 JVM과 핵심 클래스 라이브러리(Java API)가 포함되어 있지. 과거에는 JRE를 따로 설치하는 경우가 많았지만, 요즘 JDK에는 JRE가 포함되어 나오는 경우가 대부분이야.
*   **JDK (Java Development Kit)**: '자바 개발 키트'라는 뜻으로, 자바 프로그램을 *개발*하기 위해 필요한 모든 도구를 모아 놓은 종합 선물 세트와 같아. JRE를 포함하고 있을 뿐만 아니라, 개발에 필수적인 컴파일러(`javac`), 디버거, 문서 생성 도구(`javadoc`) 등 다양한 유틸리티를 제공해 줘. 개발자라면 당연히 JDK를 설치해야 하는 이유를 이제 확실히 알게 되었지.

정리하면, 나는 **JDK로 개발하고 → JRE로 실행하며 → JVM 위에서 프로그램이 동작한다**는 흐름을 이해했어.

### `javac`와 여러 소스 파일 컴파일하기

여러 개의 자바 소스 파일이 있을 때 `javac` 명령어를 어떻게 써야 할지 궁금했어. 결론부터 말하면, `javac`는 매우 유연하게 여러 파일을 처리할 수 있었어.

**문제 상황**: 내가 `Calculator.java`, `AddOperation.java`, `SubOperation.java` 세 개의 파일을 만들었다고 가정해 보자.

```java
// Calculator.java
public class Calculator {
    public static void main(String[] args) {
        int a = 10;
        int b = 5;

        // 덧셈
        AddOperation adder = new AddOperation();
        System.out.println("덧셈 결과: " + adder.calculate(a, b));

        // 뺄셈
        SubOperation subtractor = new SubOperation();
        System.println("뺄셈 결과: " + subtractor.calculate(a, b));
    }
}
```

```java
// AddOperation.java
public class AddOperation {
    public int calculate(int num1, int num2) {
        return num1 + num2;
    }
}
```

```java
// SubOperation.java
public class SubOperation {
    public int calculate(int num1, int num2) {
        return num1 - num2;
    }
}
```

**나쁜 설계 또는 오해**: 처음에는 `javac Calculator.java`만 실행하면 `Calculator.java` 파일만 컴파일되고, `AddOperation.java`나 `SubOperation.java`는 따로 컴파일해야 하는 줄 알았어. 아니면 `javac` 명령어를 파일마다 반복해서 입력해야 한다고 생각했지.

**개선된 설계 및 이해**: 실제로는 `javac`가 의존 관계를 알아서 추적해서 처리해 줘.

1.  **명시적으로 여러 파일 지정**: 가장 확실한 방법은 모든 파일을 직접 지정하는 거야.
    ```bash
    javac Calculator.java AddOperation.java SubOperation.java
    ```
    이 명령어를 실행하면 세 개의 `.java` 파일이 각각 `Calculator.class`, `AddOperation.class`, `SubOperation.class` 파일로 컴파일되어 같은 디렉토리에 생성돼.
2.  **와일드카드 문자 사용**: 만약 현재 디렉토리에 있는 모든 `.java` 파일을 컴파일하고 싶다면 와일드카드 문자 `*`를 사용할 수 있어.
    ```bash
    javac *.java
    ```
    이 명령어를 실행하면 현재 디렉토리의 모든 `.java` 파일이 컴파일돼. 내가 위에 만든 세 개의 파일도 모두 `.class` 파일로 변환되지.
3.  **메인 파일만 컴파일**: 만약 `Calculator.java` 파일이 `AddOperation`과 `SubOperation` 클래스를 사용하고 있다면, `javac`는 `Calculator.java`를 컴파일할 때 `AddOperation.java`와 `SubOperation.java` 파일을 자동으로 찾아서 함께 컴파일해 줘.
    ```bash
    javac Calculator.java
    ```
    이 명령어 하나만으로도 `Calculator.java`가 의존하는 `AddOperation.java`와 `SubOperation.java`까지 모두 `.class` 파일로 컴파일되는 걸 볼 수 있었어! 이건 정말 편리한 기능이었지.

**그래서 이해한 점**: `javac`는 자바 **컴파일러(compiler)**의 약자인데, 이 컴파일러가 소스 코드(`.java` 파일)를 바이트코드(`.class` 파일)로 번역해주는 역할을 해. 개발자가 여러 파일을 일일이 지정하지 않아도, `javac`가 의존성 관계를 파악해서 필요한 모든 파일을 컴파일해준다는 사실을 알게 되었지. 덕분에 대규모 프로젝트에서도 컴파일 과정을 효율적으로 관리할 수 있다는 것을 깨달았어.

### `java` 명령어로 컴파일된 파일 실행하기

`java` 명령어를 이용해 컴파일된 파일을 실행할 때, 어떤 파일을 어떤 형식으로 지정해야 하는지 헷갈렸어. 결론은 `.class` 확장자를 붙이지 않은 '클래스 이름'을 사용한다는 것이었지.

**문제 상황**: 위에서 컴파일했던 `Calculator.class` 파일을 실행하고 싶어.
`Calculator.java` 파일에는 `public static void main(String[] args)` 메소드가 정의되어 있어. 이 메소드가 프로그램의 시작점 역할을 하는 '메인 메소드'야.

**나쁜 설계 또는 오해**: 처음에는 `java Calculator.java`처럼 소스 파일 이름으로 실행하거나, `java Calculator.class`처럼 `.class` 확장자까지 붙여서 실행해야 하는 줄 알았어.

**개선된 설계 및 이해**: `java` 명령어는 `.class` 파일을 직접 참조하는 것이 아니라, 해당 클래스의 이름을 통해 JVM이 클래스 로더를 이용해 `.class` 파일을 찾아 메모리로 로드하고 실행해.

*   **올바른 실행 방법**:
    ```bash
    java Calculator
    ```
    이 명령어를 실행하면 `Calculator`라는 이름의 클래스를 찾아 그 안에 있는 `main` 메소드를 실행하게 돼. 결과는 다음과 같이 출력될 거야.
    ```
    덧셈 결과: 15
    뺄셈 결과: 5
    ```

*   **잘못된 실행 시도 예시**:
    ```bash
    java Calculator.java  # 에러 발생: Error: Could not find or load main class Calculator.java
    ```
    이 경우 `java` 명령어가 `Calculator.java`라는 이름의 클래스를 찾으려고 시도하지만, 그런 클래스는 없기 때문에 에러가 발생해.

    ```bash
    java Calculator.class # 에러 발생: Error: Could not find or load main class Calculator.class
    ```
    마찬가지로 `java` 명령은 `.class` 확장자를 붙인 이름으로 클래스를 찾지 않아.

    ```bash
    java AddOperation # 에러 발생: Main method not found in class AddOperation
    ```
    `AddOperation.class` 파일은 존재하지만, 이 클래스에는 `main` 메소드가 없기 때문에 실행할 수 없다는 에러가 발생해. `java` 명령은 `main` 메소드가 있는 클래스만 실행할 수 있다는 것을 명심해야 해.

**그래서 이해한 점**: `java`는 자바 **런처(launcher)**라고 부르는 도구인데, 이 런처가 JVM을 시작시키고, 우리가 지정한 클래스(이름)를 JVM이 찾아서 로드한 뒤 그 클래스 안의 `main` 메소드부터 프로그램을 실행시켜주는 역할을 해. 즉, `java` 명령어는 소스 파일이 아니라 **컴파일된 클래스의 이름**을 인자로 받는다는 것을 명확히 알게 되었어.

### 인텔리제이 같은 IDE의 역할 이해하기

인텔리제이에서 '실행' 버튼 하나만 누르면 모든 복잡한 과정이 자동으로 처리되는 것이 늘 신기했어. 이제는 그 뒤에서 어떤 일이 일어나는지 명확히 이해할 수 있게 되었지.

**문제 상황**: 내가 인텔리제이에서 `HelloWorld.java` 파일을 수정하고 'Run' 버튼을 눌렀을 때, 내부적으로 어떤 일이 일어나는지 궁금했어.

```java
// HelloWorld.java (IntelliJ 프로젝트 내)
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, IntelliJ!"); // 내용을 수정했다고 가정
    }
}
```

**나쁜 설계 또는 오해**: 인텔리제이가 그냥 마법처럼 코드를 실행시켜 주는 줄 알았어. 아니면 단 한 번의 명령으로 모든 게 이뤄지는 줄 알았지.

**개선된 설계 및 이해**: 인텔리제이(또는 다른 IDE)는 개발자의 편의를 위해 다음과 같은 일련의 과정을 자동으로 수행해 줘.

1.  **코드 저장 및 변경 감지**: 내가 파일을 수정하고 저장하면, 인텔리제이는 어떤 파일이 변경되었는지 감지해.
2.  **증분 컴파일(Incremental Compilation)**: 모든 `.java` 파일을 처음부터 다시 컴파일하는 것이 아니라, 변경된 파일과 그에 의존하는 파일들만 효율적으로 다시 컴파일해. 이때 내부적으로 `javac` 명령어를 사용해서 `.java` 파일을 `.class` 파일로 변환하는 거야. 이 과정에서 `src` 폴더에 있는 소스 코드가 `out` 또는 `build` 폴더와 같은 곳에 `.class` 파일로 생성돼.
    ```bash
    # (인텔리제이 내부적으로 실행되는 명령어 예시)
    javac -d out/production/myproject src/HelloWorld.java src/AnotherClass.java ...
    ```
    여기서 `-d` 옵션은 컴파일된 `.class` 파일이 생성될 디렉토리를 지정하는 거야.
3.  **클래스패스 설정**: 컴파일된 `.class` 파일들이 어디에 있는지, 그리고 필요한 라이브러리(JAR 파일)는 어디에 있는지를 JVM이 알 수 있도록 '클래스패스(Classpath)'를 설정해 줘.
4.  **JVM 실행 및 메인 클래스 로드**: 설정된 클래스패스를 바탕으로 JVM을 시작시키고, 프로젝트의 실행 시작점(`main` 메소드가 있는 클래스)으로 지정된 클래스를 `java` 명령어로 실행해.
    ```bash
    # (인텔리제이 내부적으로 실행되는 명령어 예시)
    java -classpath out/production/myproject HelloWorld
    ```
    여기서 `-classpath` 옵션은 JVM이 클래스 파일을 찾을 경로를 지정해주는 역할을 해.

**그래서 이해한 점**: 인텔리제이와 같은 IDE는 마치 숙련된 조교처럼, 내가 '실행'이라는 간단한 요청만 해도 뒤에서 `javac`와 `java` 명령어를 적절한 옵션과 함께 실행시켜 주는 역할을 하는 거야. 파일 저장, 컴파일, 클래스패스 설정, JVM 실행 및 메인 클래스 로드까지 이 모든 복잡한 단계를 자동으로 처리해 줌으로써 개발자가 온전히 비즈니스 로직 작성에만 집중할 수 있게 도와주는 것이었어. 내가 직접 명령 프롬프트에서 일일이 명령어를 입력하던 시절을 생각하면 정말 큰 발전이라고 느꼈지. IDE의 편리함 뒤에는 자바의 기본 컴파일 및 실행 원리가 그대로 숨어 있었다는 것을 알게 되었어.