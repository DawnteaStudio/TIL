# PostgreSQL 데이터베이스 Access privileges 읽는 법

[상위로 이동](../README.md)

## 목차

- [개념](#개념)
- [핵심 내용](#핵심-내용)
- [주의할 점](#주의할-점)
- [관련 notes](#관련-notes)
- [참고 자료](#참고-자료)

## 개념

`psql`에서 `\l` 또는 `\list`를 실행하면 데이터베이스별 `Access privileges`를 확인할 수 있다. 이 값은 각 데이터베이스의 접근 제어 목록(ACL)을 요약한 것이다.

ACL 한 항목은 **누가 권한을 받았는지**, **어떤 권한을 받았는지**, **누가 그 권한을 부여했는지**를 다음 형식으로 나타낸다.

```text
권한을 받은 역할=권한 문자/권한을 부여한 역할
```

`Access privileges`가 완전히 비어 있어도 권한이 없다는 뜻은 아니다. 빈칸은 별도의 ACL이 저장되지 않아 PostgreSQL의 내장 기본 권한을 사용한다는 의미다.

## 핵심 내용

### ACL의 기본 형식

다음 ACL을 예로 들어 보자.

```text
app_role=c/db_owner
```

- `app_role`: 권한을 받은 역할(grantee)
- `c`: 부여된 권한
- `db_owner`: 권한을 부여한 역할(grantor)

따라서 `/db_owner`는 경로나 데이터베이스 이름이 아니다.

권한 문자 뒤에 `*`가 붙으면 해당 권한을 다른 역할에 다시 부여할 수 있는 `WITH GRANT OPTION`까지 받았다는 뜻이다.

### 데이터베이스 권한 문자

데이터베이스 권한 문자는 대소문자를 구분한다.

| 문자 | 권한 | 의미 |
| --- | --- | --- |
| `C` | `CREATE` | 데이터베이스 안에 새 스키마나 publication을 만들고 trusted extension을 설치할 수 있다. |
| `c` | `CONNECT` | 데이터베이스에 접속할 수 있다. |
| `T` | `TEMPORARY` | 접속 중에 사용할 임시 테이블을 만들 수 있다. |

따라서 다음 ACL은 `db_owner`가 세 권한을 모두 가지고 있으며, 권한을 부여한 역할도 `db_owner`라는 뜻이다.

```text
db_owner=CTc/db_owner
```

### 왼쪽이 비어 있으면 `PUBLIC`

다음처럼 `=` 왼쪽이 비어 있을 수 있다.

```text
=T/db_owner
```

이 빈자리는 이름 없는 역할이 아니라 모든 역할을 포함하는 `PUBLIC`을 의미한다.

따라서 위 항목은 `db_owner`가 `PUBLIC`에 `TEMPORARY` 권한을 부여했다는 뜻이다.

전체 ACL이 다음과 같다면:

```text
db_owner=CTc/db_owner
app_role=c/db_owner
=T/db_owner
```

각 항목은 다음과 같이 해석할 수 있다.

- `db_owner`는 `CREATE`, `TEMPORARY`, `CONNECT` 권한을 가진다.
- `app_role`은 `CONNECT` 권한을 가진다.
- `PUBLIC`에는 `TEMPORARY` 권한만 남아 있다.

즉 `PUBLIC`의 기본 `CONNECT` 권한을 회수하고, 접속이 필요한 역할에만 `CONNECT`를 명시적으로 부여한 형태다.

### 빈칸과 `(none)`은 다르다

`Access privileges`에는 비슷해 보이지만 의미가 다른 세 가지 상태가 있다.

| 표시 | 의미 |
| --- | --- |
| `=T/db_owner` | `PUBLIC`에 `TEMPORARY` 권한을 명시적으로 부여한 ACL 항목 |
| 완전히 빈칸 | 시스템 카탈로그의 ACL이 `NULL`이며 내장 기본 권한을 사용함 |
| `(none)` | ACL은 존재하지만 누구에게도 일반 권한이 부여되지 않음 |

데이터베이스가 내장 기본 권한을 사용할 때의 권한은 다음과 같다.

| 대상 | 기본 권한 |
| --- | --- |
| 데이터베이스 소유자 | `CREATE`, `TEMPORARY`, `CONNECT` (`CTc`) |
| `PUBLIC` | `TEMPORARY`, `CONNECT` (`Tc`) |

따라서 권한 칸이 비어 있는 데이터베이스는 다른 접속 조건이 허용되는 한, `LOGIN` 가능한 역할이 기본적으로 접속할 수 있다.

### 현재 역할의 유효 권한 확인하기

ACL 문자열을 직접 해석하는 대신 `has_database_privilege`로 현재 역할의 유효 권한을 확인할 수 있다.

```sql
SELECT
  has_database_privilege(current_user, 'target_db', 'CONNECT') AS can_connect,
  has_database_privilege(current_user, 'target_db', 'CREATE') AS can_create,
  has_database_privilege(current_user, 'target_db', 'TEMPORARY') AS can_create_temporary;
```

이 쿼리는 대상 데이터베이스에 접속하거나 권한을 변경하지 않고 권한 정보만 조회한다.

예를 들어 결과가 다음과 같다면 현재 역할은 접속과 임시 테이블 생성은 가능하지만, 데이터베이스 수준의 `CREATE` 권한은 없다.

```text
 can_connect | can_create | can_create_temporary
-------------+------------+----------------------
 t           | f          | t
```

## 주의할 점

- `Access privileges`의 빈칸을 권한 없음으로 해석하면 안 된다. 빈칸은 내장 기본 권한을 의미하고, 실제로 아무 권한도 부여되지 않은 상태는 `(none)`으로 표시된다.
- `PUBLIC`은 특정 계정이 아니라 모든 역할을 포함하는 특수한 그룹이다.
- `CONNECT` 권한이 있어도 실제 접속이 항상 성공하는 것은 아니다. `pg_hba.conf`, 데이터베이스의 연결 허용 설정, 연결 수 제한 등의 조건도 함께 적용된다.
- 데이터베이스의 `CREATE` 권한과 스키마의 `CREATE` 권한은 서로 다르다. 일반 테이블을 만들려면 대상 스키마에 대한 권한도 필요하다.
- 데이터베이스 접속 권한이 있다고 해서 내부 테이블을 조회할 수 있는 것은 아니다. 스키마와 테이블 권한은 별도로 확인해야 한다.
- `has_database_privilege`는 역할 상속 등을 반영한 유효 권한을 확인한다. `SET ROLE`을 사용했다면 `current_user`는 처음 로그인한 역할과 다를 수 있다.

## 관련 notes

## 참고 자료

- [PostgreSQL 공식 문서 - Privileges](https://www.postgresql.org/docs/current/ddl-priv.html)
- [PostgreSQL 공식 문서 - System Information Functions and Operators](https://www.postgresql.org/docs/current/functions-info.html)
