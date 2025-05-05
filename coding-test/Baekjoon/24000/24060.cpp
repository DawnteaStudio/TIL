#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
int N, chance, cnt = 0;
// # A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// # A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(int arr[], int p, int q, int r)
{
    int i, j, t;
    int *tmp = new int[N];
    i = p;
    j = q + 1;
    t = 0;
    while (i <= q && j <= r)
    {
        if (arr[i] <= arr[j])
            tmp[t++] = arr[i++];
        else
            tmp[t++] = arr[j++];
    }
    while (i <= q)  // 왼쪽 배열 부분이 남은 경우
        tmp[t++] = arr[i++];
    while (j <= r)  // 오른쪽 배열 부분이 남은 경우
        tmp[t++] = arr[j++];
    i = p;
    t = 0;
    while (i <= r)
    {  // 결과를 A[p..r]에 저장
        arr[i++] = tmp[t++];
        cnt++;
        if (cnt == chance)
            cout << arr[i - 1];
    }
    delete[] tmp;
}

void merge_sort(int arr[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;       // q는 p, r의 중간 지점
        merge_sort(arr, p, q);      // 전반부 정렬
        merge_sort(arr, q + 1, r);  // 후반부 정렬
        merge(arr, p, q, r);        // 병합
    }
}

int main()
{
    fast;
    cin >> N >> chance;
    int *arr = new int[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    merge_sort(arr, 0, N-1);

    if (cnt < chance)
        cout << -1;

    delete[] arr;
}