[⬅️ 상위 README로 이동](../README.md)

## 📘 알고리즘: Union-Find (Disjoint Set Union, DSU)

## 📌 목차

* [1. 개념 소개](#1-개념-소개)
* [2. 주요 용어](#2-주요-용어)
* [3. 핵심 연산](#3-핵심-연산)
* [4. 최적화 기법](#4-최적화-기법)
* [5. 예시 코드](#5-예시-코드)
* [6. 성능 비교](#6-성능-비교--방식별-트리-구조와-시간-복잡도)
* [7. rank를 사용하는 이유](#7-rank를-사용하는-이유)
* [8. parent와 rank의 차이](#8-parent와-rank의-차이)
* [9. rank 증가 시 시각적 예시](#9-rank-증가-시-시각적-예시)
* [📌 참고 자료](#-참고-자료)

---

### **1. 개념 소개**

- Union-Find는 **서로소(Disjoint) 집합**을 효율적으로 관리하기 위한 자료구조이다.
- 일반적으로 **같은 그룹에 속하는지 확인**하거나, **두 그룹을 하나로 합치는 연산**이 반복되는 문제에서 사용된다.
- `find()`와 `union()` 연산을 빠르게 수행하는 것이 핵심이다.

---

### **2. 주요 용어**

| 용어        | 의미 |
|-------------|------|
| 대표 노드   | 한 집합을 대표하는 루트 노드 |
| parent 배열 | 각 원소가 가리키는 부모 노드 정보 |
| rank 배열   | 해당 노드가 루트일 때의 트리 깊이 추정값 |
| 서로소 집합 | 교집합이 없는 집합들로 구성된 그룹 |

📌 `parent[]`는 집합 구조를 유지하는 데 사용되며, `rank[]`는 병합 시 최적화를 위해 사용된다.

---

### **3. 핵심 연산**

#### 3-1. `find(x)`  
- `x`가 속한 **집합의 대표 노드(루트)**를 반환한다.
- 루트를 찾는 동안 **경로 압축(Path Compression)** 기법을 적용하여 트리를 평탄화한다.

```c
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
```

#### 3-2. `union(x, y)`  
- `x`와 `y`가 속한 **두 집합을 병합**한다.
- 트리 높이를 고려하여 **랭크가 낮은 트리를 높은 트리에 붙인다**.

```c
void unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}
```

---

### **4. 최적화 기법**

| 기법              | 설명 |
|-------------------|------|
| 경로 압축         | `find()` 호출 시 트리 경로를 평탄화 |
| 랭크 기반 병합    | 높이가 작은 트리를 큰 트리에 병합하여 트리 깊이 최소화 |
| 시간 복잡도       | 두 최적화를 함께 사용할 경우 `O(α(N))`으로 매우 빠름<br>(α: 역 아커만 함수, 실질적으로 상수) |

---

### **5. 예시 코드**

```c
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, rank;

void makeSet(int n) {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    makeSet(7);
    unionSets(1, 2);  // rank[1] = 1
    unionSets(3, 4);  // rank[3] = 1
    unionSets(1, 3);  // rank[1] = 2
    unionSets(5, 6);
    unionSets(6, 7);
    unionSets(1, 7);  // 최종 병합
    cout << "find(4): " << find(4) << '\n';
    cout << "find(7): " << find(7) << '\n';
}
```

---

### **6. 성능 비교 – 방식별 트리 구조와 시간 복잡도**

Union-Find 자료구조는 `find()`와 `union()` 연산을 반복적으로 수행하기 때문에, 이 연산들의 **시간 복잡도와 구조적 효율성**이 매우 중요하다.  
아래는 대표적인 네 가지 방식에 대한 트리 구조 및 성능 비교이다.

---

#### ✅ 비교 요약표

| 방식                | 트리 구조        | `find()` 시간복잡도 | `union()` 시간복잡도 | 특징 |
|---------------------|------------------|----------------------|------------------------|------|
| 단순 병합           | 한쪽으로 치우침   | O(N)                 | O(N)                   | 비효율적, 최악의 구조 |
| 랭크 기반 병합      | 균형 트리 유지    | O(α(N))              | O(α(N))                | 트리 깊이 제어 |
| 경로 압축만 사용    | 선형 구조 감소    | 평균 O(log N)        | O(N)                   | 트리 재구성은 됨 |
| 두 최적화 동시 사용 | 거의 평탄화 구조  | O(α(N))              | O(α(N))                | 가장 빠름, 실전 표준 |

> 💡 여기서 α(N)은 역 아커만 함수 (Inverse Ackermann Function)로, 실질적으로 O(1)이라 생각해도 무방하다.

---

#### 6-1. 단순 병합 (No Optimization)

- **구현:**
  ```cpp
  void unionSets(int a, int b) {
      parent[b] = a;
  }
  int find(int x) {
      if (parent[x] == x) return x;
      return find(parent[x]);
  }
  ```

- **트리 구조 예시:**
  ```
  1 - 2 - 3 - 4 - 5 - 6 - ... - N
  ```

- **특징:**
  - 트리 깊이가 계속 깊어짐 → `find()`가 느려짐
  - 시간복잡도 O(N), 비효율적
  - 실전에서 절대 사용하지 않음

---

#### 6-2. 랭크 기반 병합 (Union by Rank Only)

- **구현:**
  ```cpp
  void unionSets(int a, int b) {
      if (rank[a] < rank[b]) swap(a, b);
      parent[b] = a;
      if (rank[a] == rank[b]) rank[a]++;
  }
  int find(int x) {
      if (parent[x] == x) return x;
      return find(parent[x]);
  }
  ```

- **트리 구조 예시:**
  ```
      1
     /|\
    2 3 4
  ```

- **특징:**
  - `union()` 시 깊은 트리로 병합하여 균형 유지
  - `find()`는 경로 압축 없기 때문에 깊이에 따라 느려질 수 있음
  - O(log N) 수준

---

####  6-3. 경로 압축만 사용 (Path Compression Only)

- **구현:**
  ```cpp
  int find(int x) {
      if (parent[x] != x)
          parent[x] = find(parent[x]);
      return parent[x];
  }
  void unionSets(int a, int b) {
      parent[find(b)] = find(a);
  }
  ```

- **트리 구조 예시:**

  초기:
  ```
  1 - 2 - 3 - 4 - 5
  ```

  `find(5)` 이후:
  ```
  1
  ├─ 2
  ├─ 3
  ├─ 4
  └─ 5
  ```

- **특징:**
  - `find()`는 평탄화되며 점점 빨라짐
  - `union()`은 비효율적이어서 깊은 트리가 생길 수 있음
  - 실전에서는 자주 사용되는 간단한 최적화 방식

---

#### 6-4. 경로 압축 + 랭크 기반 병합 (Full Optimization)

- **구현:**
  ```cpp
  int find(int x) {
      if (parent[x] != x)
          parent[x] = find(parent[x]);
      return parent[x];
  }

  void unionSets(int a, int b) {
      a = find(a); b = find(b);
      if (a != b) {
          if (rank[a] < rank[b]) swap(a, b);
          parent[b] = a;
          if (rank[a] == rank[b]) rank[a]++;
      }
  }
  ```

- **트리 구조 예시:**
  ```
      1
    ┌─┼─┬─┐
   2  3  4  5
  ```

- **특징:**
  - `find()`와 `union()` 모두 최적화
  - 이론적으로 O(α(N)), 실전에서는 거의 O(1)처럼 작동
  - 대회나 실무에서 표준으로 사용됨

---

#### 📘 실용적 결론

- 단순 병합: 절대 사용 ❌
- 경로 압축만: 간단하고 성능 괜찮음 ⭕
- 랭크만: 트리 구조 좋지만 완전 최적화는 아님
- 둘 다: 최상의 성능, **실전 필수** ⭕⭕

---

### **7. rank를 사용하는 이유**

- `union()` 연산에서 무작위로 병합하면 트리 구조가 **선형(일자형)**으로 길어질 수 있다.
- `rank`는 각 루트 노드가 트리의 루트일 때의 **깊이(추정값)**를 의미하며, **작은 트리를 큰 트리에 병합**함으로써 **트리 높이 증가를 억제**한다.
- 이를 통해 `find()` 연산에서 루트까지의 경로가 짧아져 전체 연산 속도를 향상시킬 수 있다.
- **경로 압축과 함께 사용하면 이론적으로 O(α(N))**의 시간복잡도를 얻는다.

---

### **8. parent와 rank의 차이**

| 요소     | 의미                                   | 역할                          |
|----------|----------------------------------------|-------------------------------|
| `parent` | 각 노드가 **가리키는 부모 노드**를 저장 | 트리 구조 표현 (집합 구조 유지) |
| `rank`   | 루트 노드 기준 **트리의 깊이 추정값**     | 병합 시 어느 쪽을 루트로 둘지 결정 |

- `parent[]`는 실제 트리 구조를 나타냄 (ex: `parent[4] = 2`이면 4의 부모가 2)
- `rank[]`는 트리 깊이 비교용이므로 항상 정확한 깊이는 아님. **단지 비교 목적**으로 사용됨
- 경로 압축을 해도 `rank`는 갱신되지 않음

---

### **9. rank 증가 시 시각적 예시**

초기 상태 (`rank = 0`):

```
1   2   3   4
```

#### Step 1: union(1, 2)

- rank[1] == rank[2] → 한쪽을 루트로, rank[1]++
```
1(rank=1)
└── 2(rank=0)
```

#### Step 2: union(3, 4)

```
3(rank=1)
└── 4(rank=0)
```

#### Step 3: union(1, 3)

- rank[1] == rank[3] → rank[1]++
```
      1(rank=2)
     /   2     3(rank=1)
           └── 4
```

📌 이처럼 **같은 높이(rank 1)** 의 트리를 병합하면, **루트의 rank가 2**로 증가하고  
트리 깊이도 2가 되어 성능이 유지된다.

---

## 📌 참고 자료

