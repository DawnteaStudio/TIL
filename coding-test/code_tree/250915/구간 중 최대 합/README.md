# [구간 중 최대 합](https://www.codetree.ai/trails/complete/curated-cards/intro-max-sum-of-subarray)

|유형|문제 경험치|난이도|
|---|---|---|
|[Trail 2 / 완전탐색 I / 구간 단위로 완전탐색](https://www.codetree.ai/trail-info/novice-mid/)|[[Concept]구간 중 최대 합](https://www.codetree.ai/trails/complete/curated-cards/intro-max-sum-of-subarray/)|쉬움|

## 풀이

길이 K인 구간의 시작점을 0부터 N−K까지 옮기며 매번 원소 K개의 합을 구합니다. 가능한 모든 구간을 한 번씩 비교하므로 시간은 O((N−K+1) × K), 입력 배열 외 추가 공간은 O(1)입니다. 배열이 `1 5 2 4 3`이고 K가 3이면 세 구간의 합은 8, 11, 9이므로 답은 11입니다.

구간이 한 칸 이동할 때 빠지는 값은 빼고 새 값은 더하면 O(N)으로 줄일 수 있습니다. 음수까지 허용하는 문제로 바꾼다면 최댓값의 초기값은 첫 구간의 합으로 잡아야 합니다.

<!-- codetree:navigation:start -->
[이날의 문제 목록](../README.md) · [풀이 코드 · max-sum-of-subarray.cpp](./max-sum-of-subarray.cpp)
<!-- codetree:navigation:end -->
