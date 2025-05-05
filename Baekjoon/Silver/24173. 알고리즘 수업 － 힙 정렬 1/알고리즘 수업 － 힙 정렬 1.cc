#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
int N, chance, cnt = 0;

// A[k]를 루트로 하는 트리를 최소 힙 성질을 만족하도록 수정한다.
// A[k]의 두 자식을 루트로 하는 서브 트리는 최소 힙 성질을 만족하고 있다.
// n은 배열 A의 전체 크기이며 최대 인덱스를 나타낸다.
void heapify(int arr[], int k, int n)
{
    int left, right, smaller, tmp;

    left = 2 * k;
    right = 2 * k + 1;
    if (right <= n)
    {
        if (arr[left] < arr[right])
            smaller = left;
        else 
            smaller = right;
    }
    else if (left <= n)
        smaller = left;
    else
        return;

    // 최소 힙 성질을 만족하지 못하는 경우 재귀적으로 수정한다.
    if (arr[smaller] < arr[k])
    {
        tmp = arr[k];
        arr[k] = arr[smaller];
        arr[smaller] = tmp;
        cnt++;
        if (cnt == chance)
        {
            cout << arr[k] << ' ' << arr[smaller];
            return ;
        }
        heapify(arr, smaller, n);
    }
}

void build_min_heap(int arr[], int n)
{
    for(int i = n/2; i >= 1; i--)
        heapify(arr, i, n);
}

void heap_sort(int arr[], int n) // A[1..n]을 정렬한다.
{
    int tmp;
    build_min_heap(arr, n);
    for (int i = n; i >= 2; i--)
    {
        tmp = arr[1];
        arr[1] = arr[i];
        arr[i] = tmp;  // 원소 교환
        cnt++;
        if (chance == cnt)
        {
            cout << arr[i] << ' ' << arr[1];
            return ;
        }
        heapify(arr, 1, i - 1);
    }
}


int main()
{
    fast;
    cin >> N >> chance;
    int *arr = new int[N+1];

    for (int i = 1; i < N+1; i++)
        cin >> arr[i];
    heap_sort(arr, N);
    if (cnt < chance)
        cout << -1;

    delete[] arr;
}