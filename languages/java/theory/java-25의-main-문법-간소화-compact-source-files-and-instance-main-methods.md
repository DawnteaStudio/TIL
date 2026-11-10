# Java 25의 main 문법 간소화 (Compact Source Files and Instance Main Methods)

[상위로 이동](../README.md)

## 목차

<!-- til:toc:start -->
- [개념](#개념)
- [핵심 내용](#핵심-내용)
- [주의할 점](#주의할-점)
- [참고 자료](#참고-자료)
<!-- til:toc:end -->

## 개념

Java 25에서는 'Compact Source Files 및 Instance Main Methods' (JEP 512)를 통해 `public static void main(String[] args)`와 같은 기존의 정형화된(boilerplate) 메인 메소드 선언 방식을 크게 간소화했습니다. 이 변화는 특히 초보 개발자들이나 간단한 스크립트를 작성할 때 코드를 더 간결하고 읽기 쉽게 만들고, 불필요한 구문 없이 로직에 집중할 수 있도록 돕습니다.

## 핵심 내용

- **인스턴스 Main 메소드 지원**: 더 이상 `static` 키워드가 필요 없는 인스턴스 `main()` 메소드를 사용할 수 있습니다.
- **`public`, `static`, `String[] args` 생략 가능**: 간단한 프로그램의 경우 `public`, `static` 키워드와 `String[] args` 매개변수를 생략하여 `main()` 메소드를 선언할 수 있습니다.
- **Compact Source Files (이름 없는 클래스)**: 명시적인 클래스 선언 없이 Java 소스 파일을 작성할 수 있습니다. 컴파일러가 코드를 자동으로 이름 없는 `final` 클래스로 감싸줍니다.
- **간소화된 콘솔 I/O**: `System.out.println()` 대신 `IO.println()`과 같은 헬퍼 I/O 메소드가 도입되어 콘솔 입출력이 더 간결해졌습니다.
- **실행할 메소드 선택**: 호출 가능한 `void main(String[] args)`를 먼저 찾고, 없으면 인자 없는 `void main()`을 선택합니다. 선택된 메소드가 인스턴스 메소드이면 인자 없이 클래스의 인스턴스를 만든 뒤 호출합니다.
- **초보자 친화적**: 복잡한 Java 구문을 처음부터 익힐 필요 없이 핵심 로직에 집중하여 학습 곡선을 낮추는 데 기여합니다.

## 주의할 점

- **Compact Source Files의 암묵적 특성**: Compact Source Files는 컴파일러에 의해 암묵적으로 이름 없는 `final` 클래스 내부에 래핑되며, 기본(no-arg) 생성자를 가집니다.
- **필수 Main 메소드**: Compact Source Files에서도 프로그램의 진입점 역할을 하는 `main` 메소드는 필수적으로 존재해야 합니다.
- **`IO` 클래스 메소드 호출**: `IO` 클래스 자체는 임포트가 필요 없지만, `IO.println()`과 같이 정적 메소드를 호출할 때는 명시적으로 `IO.` 접두사를 사용해야 합니다. (이전 미리보기 버전과는 변경된 사항입니다.)

## 참고 자료

- [Java 언어 명세 §7.3 · Compact Compilation Units](https://docs.oracle.com/javase/specs/jls/se25/html/jls-7.html#jls-7.3)
- [Java 언어 명세 §12.1.4 · main 메서드 선택과 호출](https://docs.oracle.com/javase/specs/jls/se25/html/jls-12.html#jls-12.1.4)
- [Java SE 25 API · java.lang.IO](https://docs.oracle.com/en/java/javase/25/docs/api/java.base/java/lang/IO.html)
