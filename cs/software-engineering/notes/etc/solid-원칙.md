# SOLID 원칙을 다시 정리하며: 헷갈렸던 OCP와 DIP까지 한 번에 묶어 이해한 기록

## 학습 출처

- Software maestro 멘토링

## 오늘 배운 것

이번에 SOLID 원칙을 다시 보면서 느낀 건, 각 원칙을 따로 외우면 금방 섞인다는 점이었다.  
처음에는 다들 “좋은 객체지향 설계” 이야기처럼 보여서 비슷비슷하게 느껴졌는데, 예시를 붙여서 보니까 각 원칙이 맡는 역할이 조금씩 다르다는 걸 이해하게 됐다.

핵심은 결국 **변화에 강한 설계**를 만드는 쪽으로 모이지만,  
각 원칙은 “무엇을 경계해야 하는지”가 다르다.

---

## 배운 내용

### 1. 단일 책임 원칙, SRP

처음엔 “클래스는 한 가지 일만 해야 한다” 정도로만 외웠다.  
그런데 이 표현만 보면 너무 추상적이라 실제 코드에서 어디까지가 한 가지 일인지 애매했다.

내가 이해한 쪽은 이렇다.

- 클래스는 **변경 이유가 하나여야 한다**
- 하나의 책임을 맡았다면 그 책임과 관련된 로직을 응집력 있게 묶어야 한다
- 서로 다른 이유로 자주 바뀌는 기능이 한 클래스에 같이 있으면 SRP 위반일 가능성이 크다

예를 들어 회원 객체에 사용자 정보뿐 아니라 암호화 로직까지 들어 있다고 해보자.

```java
public class Member {
    private String name;
    private String password;

    public Member(String name, String password) {
        this.name = name;
        this.password = encrypt(password);
    }

    private String encrypt(String password) {
        return password + "_encrypted";
    }
}
```

처음 보면 “비밀번호를 저장하니까 암호화도 회원 클래스 안에 있는 게 자연스러운 것 아닌가?” 싶다.  
그런데 생각해보면 이 클래스는 두 가지 이유로 바뀔 수 있다.

1. 회원 정보 구조가 바뀔 때
2. 암호화 정책이 바뀔 때

이렇게 되면 회원 도메인 변경과 보안 정책 변경이 한 클래스에 같이 엮인다.  
결국 읽기도 어려워지고, 수정할 때 영향 범위도 커진다.

조금 더 나누면 이렇게 볼 수 있다.

```java
public class Member {
    private String name;
    private String encryptedPassword;

    public Member(String name, String encryptedPassword) {
        this.name = name;
        this.encryptedPassword = encryptedPassword;
    }
}

public class PasswordEncoder {
    public String encrypt(String password) {
        return password + "_encrypted";
    }
}
```

이렇게 나누면 회원은 회원 데이터에 집중하고, 암호화는 암호화 정책에 집중한다.  
SRP는 단순히 클래스를 잘게 쪼개라는 뜻이 아니라, **변경 이유를 분리하라는 말**로 받아들이는 쪽이 더 맞다고 느꼈다.

---

### 2. 개방-폐쇄 원칙, OCP

OCP는 처음 볼 때 문장 자체가 약간 역설적으로 느껴졌다.  
“확장에는 열려 있고, 수정에는 닫혀 있어야 한다”는 말이 바로 와닿지는 않았다.

내가 이해한 핵심은 이것이다.

- **새 기능은 붙일 수 있어야 한다**
- **그런데 기존에 잘 동작하던 코드는 되도록 건드리지 않아야 한다**

예를 들어 동물 소리를 출력하는 코드가 있다고 해보자.

```java
public class AnimalSoundService {
    public String sound(String animalType) {
        if (animalType.equals("dog")) return "멍멍";
        if (animalType.equals("cat")) return "야옹";
        return "";
    }
}
```

처음에는 단순해서 괜찮아 보인다.  
그런데 토끼, 오리, 소가 계속 추가되면 어떻게 될까.

```java
public String sound(String animalType) {
    if (animalType.equals("dog")) return "멍멍";
    if (animalType.equals("cat")) return "야옹";
    if (animalType.equals("duck")) return "꽥꽥";
    if (animalType.equals("cow")) return "음메";
    return "";
}
```

새 동물이 추가될 때마다 기존 메서드를 계속 수정하게 된다.  
이러면 기능을 추가할 때마다 원래 코드까지 흔들린다.  
테스트 범위도 넓어지고, 실수할 가능성도 커진다.

OCP를 적용하면 구조를 이렇게 바꿔볼 수 있다.

```java
public interface Animal {
    String sound();
}

public class Dog implements Animal {
    @Override
    public String sound() {
        return "멍멍";
    }
}

public class Cat implements Animal {
    @Override
    public String sound() {
        return "야옹";
    }
}

public class AnimalSoundService {
    public String sound(Animal animal) {
        return animal.sound();
    }
}
```

이제 새 동물을 추가하고 싶으면 기존 `AnimalSoundService`를 수정하는 대신  
`Animal`을 구현한 새 클래스를 만들면 된다.

```java
public class Duck implements Animal {
    @Override
    public String sound() {
        return "꽥꽥";
    }
}
```

이 구조에서 중요한 건, **기존 동작을 담당하던 코드를 뜯어고치지 않고도 기능을 늘릴 수 있다**는 점이다.  
이게 내가 이해한 OCP의 감각이었다.

---

### 3. 인터페이스 분리 원칙, ISP

ISP는 처음엔 SRP와 비슷하게 보였다.  
둘 다 “쪼개라”는 말처럼 들리기 때문이다.

그런데 ISP는 클래스의 책임 분리보다,  
**인터페이스를 사용하는 쪽이 불필요한 기능에 의존하지 않게 만드는 것**에 더 가깝다.

예를 들어 이런 인터페이스가 있다고 해보자.

```java
public interface Worker {
    void work();
    void eat();
}
```

사람 직원이라면 괜찮아 보이지만, 만약 로봇 작업자도 같은 인터페이스를 구현해야 한다면 곤란해진다.

```java
public class RobotWorker implements Worker {
    @Override
    public void work() {
        System.out.println("작업 수행");
    }

    @Override
    public void eat() {
        throw new UnsupportedOperationException();
    }
}
```

여기서 `RobotWorker`는 `eat()`를 실제로 쓰지 않는데도 구현해야 한다.  
이건 인터페이스가 너무 많은 기능을 한꺼번에 강요하고 있다는 신호다.

조금 더 나누면 다음처럼 된다.

```java
public interface Workable {
    void work();
}

public interface Eatable {
    void eat();
}

public class HumanWorker implements Workable, Eatable {
    @Override
    public void work() {
        System.out.println("작업 수행");
    }

    @Override
    public void eat() {
        System.out.println("식사");
    }
}

public class RobotWorker implements Workable {
    @Override
    public void work() {
        System.out.println("작업 수행");
    }
}
```

이제 각 구현체는 필요한 인터페이스만 구현하면 된다.  
ISP는 결국 **클라이언트가 쓰지도 않는 메서드에 묶이지 않게 하는 설계**라고 이해하게 됐다.

---

### 4. 리스코프 치환 원칙, LSP

이 원칙은 정사각형과 직사각형 예시가 가장 많이 나오는데, 처음엔 단순히 “상속 조심하자” 정도로 받아들였다.  
그런데 포인트는 상속 자체보다 **대체 가능성**에 있었다.

부모 타입을 기대하는 자리에 자식 타입을 넣었을 때,  
프로그램이 자연스럽게 동작해야 한다는 뜻이다.

정사각형이 직사각형을 상속받는 예시를 보면 왜 문제가 되는지 드러난다.

```java
public class Rectangle {
    protected int width;
    protected int height;

    public void setWidth(int width) {
        this.width = width;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getArea() {
        return width * height;
    }
}
```

직사각형은 너비와 높이를 독립적으로 바꿀 수 있다는 전제가 있다.  
그런데 정사각형은 이 전제를 만족하지 않는다.

```java
public class Square extends Rectangle {
    @Override
    public void setWidth(int width) {
        this.width = width;
        this.height = width;
    }

    @Override
    public void setHeight(int height) {
        this.width = height;
        this.height = height;
    }
}
```

이제 아래 코드가 있다고 해보자.

```java
Rectangle rect = new Square();
rect.setWidth(5);
rect.setHeight(10);

System.out.println(rect.getArea());
```

직사각형이라고 생각하면 넓이는 50일 것 같지만,  
정사각형 구현에서는 마지막 `setHeight(10)` 때문에 너비와 높이가 모두 10이 되어 100이 나온다.

즉, `Rectangle`을 기대하고 만든 코드에 `Square`를 넣었더니 의미가 깨져버린다.  
이건 단순한 구현 차이가 아니라, **부모 타입의 계약을 자식이 지키지 못한 상태**다.

그래서 LSP는 이렇게 받아들이게 됐다.

- 상속은 “is-a”처럼 보여도 충분하지 않다
- 자식이 부모 자리에 들어가도 기존 코드의 기대를 깨지 않아야 한다
- 치환했을 때 동작 의미가 달라진다면 잘못된 상속이다

---

### 5. 의존 역전 원칙, DIP

처음에 가장 헷갈렸던 건 이 원칙이었다.  
문장은 알겠는데, OCP와 자꾸 섞였다.  
게다가 왜 이름이 “역전”인지도 감이 잘 안 왔다.

기본 문장은 이렇다.

- 고수준 모듈은 저수준 모듈에 의존하면 안 된다
- 둘 다 추상화에 의존해야 한다
- 구체적인 구현보다 인터페이스나 추상 클래스에 의존하는 쪽이 낫다

말만 보면 조금 추상적이라 예시로 봐야 이해가 됐다.

```java
public class MySqlMemberRepository {
    public void save(String name) {
        System.out.println("MySQL에 저장: " + name);
    }
}

public class MemberService {
    private final MySqlMemberRepository repository = new MySqlMemberRepository();

    public void register(String name) {
        repository.save(name);
    }
}
```

이 구조에서는 `MemberService`가 `MySqlMemberRepository`라는 구체 클래스에 직접 묶여 있다.  
저장소가 파일 저장으로 바뀌거나, 테스트용 가짜 저장소를 쓰고 싶으면 서비스 코드를 같이 수정해야 한다.

DIP를 적용하면 중간에 추상화를 둔다.

```java
public interface MemberRepository {
    void save(String name);
}
```

```java
public class MySqlMemberRepository implements MemberRepository {
    @Override
    public void save(String name) {
        System.out.println("MySQL에 저장: " + name);
    }
}
```

```java
public class MemoryMemberRepository implements MemberRepository {
    @Override
    public void save(String name) {
        System.out.println("메모리에 저장: " + name);
    }
}
```

```java
public class MemberService {
    private final MemberRepository repository;

    public MemberService(MemberRepository repository) {
        this.repository = repository;
    }

    public void register(String name) {
        repository.save(name);
    }
}
```

이제 `MemberService`는 더 이상 MySQL 구현체 자체를 알 필요가 없다.  
그냥 “저장할 수 있는 무언가”에만 의존한다.

이 구조가 좋은 이유는 명확하다.

- 구현체를 바꿔도 서비스 코드는 덜 흔들린다
- 테스트가 쉬워진다
- 고수준 정책과 저수준 구현이 느슨하게 연결된다

---

## 헷갈린 지점

- 개방-폐쇄 원칙과 의존 역전 원칙의 차이가 계속 섞였다
- 의존 역전에서 “역전”이 정확히 무엇이 뒤집힌다는 뜻인지 처음엔 감이 오지 않았다

---

## 실험하며 비교해 본 흐름

내가 가장 헷갈렸던 건 결국  
“OCP도 인터페이스 얘기 같고, DIP도 인터페이스 얘기 같은데 뭐가 다르지?”였다.

그래서 같은 예시를 두 원칙 관점으로 나눠서 보면 훨씬 정리가 됐다.

### 문제 상황: 결제 수단이 계속 추가되는 코드

처음에 이런 코드가 있다고 해보자.

```java
public class PaymentService {
    public void pay(String type, int amount) {
        if (type.equals("card")) {
            System.out.println("카드 결제: " + amount);
        } else if (type.equals("kakao")) {
            System.out.println("카카오페이 결제: " + amount);
        }
    }
}
```

처음엔 단순하다.  
그런데 네이버페이, 토스페이, 계좌이체가 계속 추가되면 `if-else`가 늘어난다.

```java
public void pay(String type, int amount) {
    if (type.equals("card")) {
        System.out.println("카드 결제: " + amount);
    } else if (type.equals("kakao")) {
        System.out.println("카카오페이 결제: " + amount);
    } else if (type.equals("naver")) {
        System.out.println("네이버페이 결제: " + amount);
    }
}
```

이 구조에서 내가 처음 느낀 혼란은  
“새 기능 추가에 약하니까 OCP 위반인 건 알겠다.  
그런데 인터페이스로 바꾸면 그건 DIP인가 OCP인가?”였다.

### 왜 헷갈리는지

둘 다 결과적으로는 인터페이스를 자주 사용한다.  
그래서 코드 모양만 보면 비슷해 보인다.

하지만 초점이 다르다.

- OCP는 **새 결제 수단이 생겨도 기존 서비스 코드를 수정하지 않게 하고 싶은 목표**
- DIP는 **서비스가 구체 결제 클래스에 직접 묶이지 않고 추상화에 의존하게 만드는 구조**

즉, 같은 리팩터링 안에서도  
“왜 이걸 하는가”를 OCP로 볼 수 있고,  
“어떻게 의존을 구성하는가”를 DIP로 볼 수 있었다.

### 나쁜 설계 또는 오해

처음에는 이렇게 생각하기 쉬웠다.

- OCP = 인터페이스 쓰기
- DIP = 인터페이스 쓰기

그런데 이렇게 외우면 둘의 차이가 사라진다.  
인터페이스는 수단일 뿐이고, 원칙 자체는 역할이 다르다.

### 개선된 설계

결제 인터페이스를 둔다.

```java
public interface Payment {
    void pay(int amount);
}
```

구현체를 나눈다.

```java
public class CardPayment implements Payment {
    @Override
    public void pay(int amount) {
        System.out.println("카드 결제: " + amount);
    }
}

public class KakaoPayment implements Payment {
    @Override
    public void pay(int amount) {
        System.out.println("카카오페이 결제: " + amount);
    }
}

public class NaverPayment implements Payment {
    @Override
    public void pay(int amount) {
        System.out.println("네이버페이 결제: " + amount);
    }
}
```

서비스는 구체 클래스가 아니라 추상화에 의존하게 만든다.

```java
public class PaymentService {
    private final Payment payment;

    public PaymentService(Payment payment) {
        this.payment = payment;
    }

    public void pay(int amount) {
        payment.pay(amount);
    }
}
```

이제 새 결제 수단이 추가되면 `Payment` 구현체만 하나 더 만들면 된다.

```java
public class TossPayment implements Payment {
    @Override
    public void pay(int amount) {
        System.out.println("토스페이 결제: " + amount);
    }
}
```

### 전후 비교

기존 방식에서는 결제 수단 추가 시 `PaymentService`를 수정했다.

- 조건문이 늘어난다
- 기존 코드에 손댄다
- 테스트 범위가 커진다

바꾼 뒤에는 결제 수단 추가 시 새 클래스를 추가한다.

- 서비스 코드는 그대로 둔다
- 구현체만 확장한다
- 결제 방식이 늘어나도 구조가 덜 흔들린다

### 그래서 이해한 점

여기서 OCP와 DIP를 분리해서 보면 훨씬 편했다.

- **OCP 관점**: 결제 수단이 추가되어도 `PaymentService`를 수정하지 않고 기능을 확장할 수 있다
- **DIP 관점**: `PaymentService`가 `CardPayment`, `KakaoPayment` 같은 구체 클래스가 아니라 `Payment`라는 추상화에 의존한다

즉, OCP는 목표이고 DIP는 그 목표를 가능하게 만드는 대표적인 설계 방식 중 하나라고 정리됐다.

---

## 현재 이해한 결론

이번에 제일 크게 정리된 건 OCP와 DIP의 관계였다.

### OCP와 DIP의 차이

처음엔 둘 다 “인터페이스 써서 확장성 확보하기”처럼 보여서 구분이 잘 안 됐다.  
지금은 이렇게 구분하고 있다.

- **OCP**는 결과 또는 목표에 가깝다  
  → 새 기능을 추가할 때 기존 코드를 되도록 수정하지 않는 설계를 지향한다

- **DIP**는 의존 관계를 짜는 방식에 가깝다  
  → 고수준 로직이 구체 구현체가 아니라 추상화에 의존하도록 만든다

즉,

- OCP = “기존 코드를 고치지 말고 기능을 추가하자”
- DIP = “그걸 가능하게 하려면 구체 클래스 대신 추상화에 의존하게 만들자”

둘은 비슷한 방향을 보지만 같은 말은 아니다.  
DIP를 잘 적용하면 OCP를 지키기 쉬워지고, 그래서 둘이 자주 같이 등장했던 거였다.

### 의존 역전에서 “역전”의 의미

이 부분도 이제야 납득이 됐다.

보통 단순한 구조에서는 **고수준 정책이 저수준 구현에 의존**한다.  
예를 들면 서비스가 MySQL 저장소를 직접 생성하고 직접 호출하는 식이다.

- `MemberService -> MySqlMemberRepository`

이건 의존 방향이 구현 쪽으로 내려간다.

그런데 DIP를 적용하면 둘 다 추상화에 의존한다.

- `MemberService -> MemberRepository`
- `MySqlMemberRepository -> MemberRepository`

즉, 원래는 고수준이 저수준 구체 클래스에 끌려다녔는데,  
이제는 저수준 구현체도 추상화 규약을 따르게 된다.

여기서 “역전”은 단순히 상하가 뒤집힌다는 뜻이라기보다,  
**기존에 구체 구현 중심이던 의존 방향이 추상화 중심으로 바뀌는 것**을 말한다.

이름이 “의존 역전”인 이유도 결국  
구체 클래스가 중심이던 설계에서, 추상화가 중심이 되는 설계로 사고방식이 뒤집히기 때문이다.

### 각 원칙을 지금 기준으로 짧게 다시 정리하면

- **SRP**: 변경 이유가 하나가 되도록 책임을 나눈다
- **OCP**: 기존 코드를 크게 건드리지 않고 기능을 확장할 수 있어야 한다
- **ISP**: 쓰지 않는 기능까지 강요하는 큰 인터페이스를 피한다
- **LSP**: 자식 객체는 부모 객체 대신 들어가도 기대한 동작을 깨지 않아야 한다
- **DIP**: 구체 구현이 아니라 추상화에 의존하게 설계한다

결국 SOLID는 각각 따로 외우는 규칙이라기보다,  
코드가 바뀔 때 어디가 무너지는지 미리 막기 위한 관점 모음처럼 느껴졌다.

이번에는 특히  
**OCP는 목표, DIP는 그 목표를 돕는 설계 방식**이라는 식으로 묶어서 이해한 게 가장 큰 수확이었다.