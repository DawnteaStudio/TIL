# Java 25의 main 문법 간소화 (Compact Source Files and Instance Main Methods)

[상위로 이동](../README.md)

## 목차

- [개념](#개념)
- [핵심 내용](#핵심-내용)
- [주의할 점](#주의할-점)
- [관련 notes](#관련-notes)
- [참고 자료](#참고-자료)

## 개념

Java 25에서는 'Compact Source Files 및 Instance Main Methods' (JEP 512)를 통해 `public static void main(String[] args)`와 같은 기존의 정형화된(boilerplate) 메인 메소드 선언 방식을 크게 간소화했습니다. 이 변화는 특히 초보 개발자들이나 간단한 스크립트를 작성할 때 코드를 더 간결하고 읽기 쉽게 만들고, 불필요한 구문 없이 로직에 집중할 수 있도록 돕습니다.

## 핵심 내용

- **인스턴스 Main 메소드 지원**: 더 이상 `static` 키워드가 필요 없는 인스턴스 `main()` 메소드를 사용할 수 있습니다.
- **`public`, `static`, `String[] args` 생략 가능**: 간단한 프로그램의 경우 `public`, `static` 키워드와 `String[] args` 매개변수를 생략하여 `main()` 메소드를 선언할 수 있습니다.
- **Compact Source Files (이름 없는 클래스)**: 명시적인 클래스 선언 없이 Java 소스 파일을 작성할 수 있습니다. 컴파일러가 코드를 자동으로 이름 없는 `final` 클래스로 감싸줍니다.
- **간소화된 콘솔 I/O**: `System.out.println()` 대신 `IO.println()`과 같은 헬퍼 I/O 메소드가 도입되어 콘솔 입출력이 더 간결해졌습니다.
- **JVM의 Main 메소드 탐색 순서**: JVM은 표준 `public static void main(String[] args)`를 먼저 찾고, 없으면 `public static void main()`를, 그래도 없으면 `public` 기본 생성자를 사용하여 클래스의 인스턴스를 생성한 후 인스턴스 `main()` 메소드를 호출합니다.
- **초보자 친화적**: 복잡한 Java 구문을 처음부터 익힐 필요 없이 핵심 로직에 집중하여 학습 곡선을 낮추는 데 기여합니다.

## 주의할 점

- **Compact Source Files의 암묵적 특성**: Compact Source Files는 컴파일러에 의해 암묵적으로 이름 없는 `final` 클래스 내부에 래핑되며, 기본(no-arg) 생성자를 가집니다.
- **필수 Main 메소드**: Compact Source Files에서도 프로그램의 진입점 역할을 하는 `main` 메소드는 필수적으로 존재해야 합니다.
- **`IO` 클래스 메소드 호출**: `IO` 클래스 자체는 임포트가 필요 없지만, `IO.println()`과 같이 정적 메소드를 호출할 때는 명시적으로 `IO.` 접두사를 사용해야 합니다. (이전 미리보기 버전과는 변경된 사항입니다.)

## 관련 notes

## 참고 자료

- [Java 25: 4 Killer Features That Cut the Boilerplate - Medium](https://vertexaisearch.cloud.google.com/grounding-api-redirect/AUZIYQGE3zkXS8pXqtfrxEWSUo_7C1uI-_KkzKjekH6ij3tjjG_U-R_DRpwQg84YDVtlOYbSaSLiflq71pFJ3ee9aSX3OUDaVmfHadMkiAzkQIxEKJaUc7vlPV7yWfRpi9dvbEO3rWompnqGXoosxnqmstrG19bSbUWt9L80Wbk7vuKEswMkOOiWD59uHNtxOtk_BVXHCvEDBNYS0hIIkg==)
- [Java 25 is Released! What are the Top 7 New Features with Code! | Coding Shuttle](https://vertexaisearch.cloud.google.com/grounding-api-redirect/AUZIYQF7L66LRGkq1jhK8wkhiOUsMxXAXEvT9CbXK6LFvvPuyH4r_4kNS6Uwir2yrW4NZLXcIiq1PZsQqxPwtsamjuF0PPjjeSZq5RIGX9njM63h-RahbdIRE7r2EcfCSijuGWg-hLgBtygMKSonOgCi8O23DCvbak1cxY45W6m1UnrAUXbp3DyQv_UBVClqRtaT7DytLqCxQymMc0IToyPrO1CckLkG838ZcLnl_S1U1Grkw-1Z)
- [What's New With Java 25 - JRebel](https://vertexaisearch.cloud.google.com/grounding-api-redirect/AUZIYQF0irO6EwimM0FLPONv06t-nPe7cUC0fD3RiIZEzwwbkKlYz5RdD8on-3a-dv_iACH64pOXxCsCG3SX5t-uSQMSZnIvRAhuzOqSnQsXWONSUIMI1cgJwiwjQ8RhibxQ)
- [Java 25: The Future of Coding Made Easy | by Java Techie - Medium](https://vertexaisearch.cloud.google.com/grounding-api-redirect/AUZIYQH-d-0uQ9WVpzcHwwVIgQAZpmQ2tc2OWvd8P1jsFpmwCc1E66vGIOw0NP88IT5pMl7j863lKPDUp15yIoqQ3M2ItgeV8bffzdt_kMAGRPUZ-jEYiEob8fVapGhSibIyER8Dgspgvh1_F-3DJsH9xZ3hUl2xAZ1fIQ4N7QLYBHuF7Webm86VmROqt-LtKI=)
- [Java main() Method – With 2024/2025 Enhancements - HappyCoders.eu](https://vertexaisearch.cloud.google.com/grounding-api-redirect/AUZIYQHfHrSERxvw0O5TGWONpGdjC4KULi3NOgC-a2IDQgvElCp-GPB0UsI1kjXJRbRKedhGZIFdkfOxXVwPt_qaQ5SFZJ7rLZBUvvlvR6ZlJA_hsfRaVYcfoN1NFEbPZ0aqPOuIVfGakDK1)
- [JAVA25: Simpler, faster, cleaner - ALTIA](https://vertexaisearch.cloud.google.com/grounding-api-redirect/AUZIYQGXMrO4U4NNCoNz_Ym_jOtFVnQq8iMl3VvYdnqzcyLE0AGwHuVoB9aRADM5hKOAqkrQ0PFKj8LmpWB7eja5Q4WELM4nGIZUzMGUFS-YnblcXFDTXchdeJAatXg8WROOpp2y4qlqXUKnXtDCpt4cgtc=)
- [Java 25 : what's news? | SQLI](https://vertexaisearch.cloud.google.com/grounding-api-redirect/AUZIYQFYVr01vXiUDMI5qtHEqy-q5FrPY_Cvg9Y9tCG8IHY3s2ZT3gMUawrVlVqAy-xxag_zWirjwAdEA024qsMMn4-j1yIMprsGHLY-XNBbQOSU56lrPOFDGRJ1_-phgORwNYeT8C3MRIzDNmCU3b1TT_DqgA==)
- [What's new in Java 25 for developers - IBM Developer](https://vertexaisearch.cloud.google.com/grounding-api-redirect/AUZIYQEl-J7yd6DPyiS-q2XtxrpBHczPlw4B2zsQtfaU5I0-Xcxm-mVh_GbvnsO2mXbLazIyiqnI-1IStqRWQqjyawodEFVN2rdljRYLG852K1d_QMhSm6BT-7us9WKK1-ht8KEO5BQ1Lawt3tGzO85YD-v6UhjIsQ==)
- [Instance Main Methods Move from Preview to Final in JDK 25 - InfoQ](https://vertexaisearch.cloud.google.com/grounding-api-redirect/AUZIYQGEMCP9Er4dL8_K6qe48zEE2lVTixPrFKz6raV53-7CeO7-7u_0CqGH8zXYwqeL_X3uZpvzEcy98qQA1rBfc35UZ-PTTnn9aefxfYZnV1k6e_WEtFTTbDbj02JAYSQ1PjoZXdJxOWX7FCTRXyd9zr6sXm8x_ppgDQYUkw==)
- [Unlocking Developer Productivity with Java 25: Features You'll Actually Use - JAVAPRO](https://vertexaisearch.cloud.google.google.com/grounding-api-redirect/AUZIYQEl83wApWQ0pQ-sfV23bHS4Mr7yOGHq9w8h8j0th5_ygVhcshLm5lcD_PJsNfNIftp8sBR1V3F4GmxkfS-Fpi8hgJkKruz1kz5feDrCay7VWI10FIQdcICU8S_FR4M5VPa7GwF8Pc69Xyrt5_XC9xBNdQvEqYUegHWUGy0IQM9YUiHrI5gW1mA1rJ3DPTBS-ct1cU6NvlneHXcTFq7UwWVjM0_K)
