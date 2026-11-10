# [숫자 카운트](https://www.codetree.ai/trails/complete/curated-cards/challenge-numeric-count)

|유형|문제 경험치|난이도|
|---|---|---|
|[Trail 2 / 완전탐색 I / 자리 마다 숫자를 정하는 완전탐색](https://www.codetree.ai/trail-info/novice-mid/)|[[Challenge]숫자 카운트](https://www.codetree.ai/trails/complete/curated-cards/challenge-numeric-count/)|보통|

## 풀이

1부터 9까지 서로 다른 세 숫자를 나열한 후보는 504개입니다. 각 단서마다 자리와 숫자가 모두 맞으면 스트라이크, 숫자만 맞으면 볼로 세고, 두 수가 입력과 일치하는 후보만 남깁니다. 단서가 N개일 때 각 후보에서 세 자리만 비교하므로 시간은 O(504 × N), 공간은 최대 504개의 후보입니다.

단서 하나가 `123 3 0`이면 123만 남습니다. `123 0 0`이면 1·2·3을 제외한 여섯 숫자 중 세 개를 고르므로 120개가 남습니다.

<!-- codetree:navigation:start -->
[이날의 문제 목록](../README.md) · [풀이 코드 · numeric-count.cpp](./numeric-count.cpp)
<!-- codetree:navigation:end -->
