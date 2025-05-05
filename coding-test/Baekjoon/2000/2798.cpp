#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int N, M, tmp, res = 0;
    cin >> N >> M;

    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr+N);
    for (int i = 0; i < N; i++)
    {
        tmp = arr[i];
        for (int j = i + 1; j < N; j++)
        {
            tmp = arr[i] + arr[j];
            for (int k = j + 1; k < N; k++)
            {
                if (tmp + arr[k] > M)
                {
                    if (k == j + 1 && j == i + 1)
                    {
                        cout << res;
                        return 0;
                    }
                    break;
                }
                if (tmp + arr[k] > res)
                    res = tmp + arr[k];
            }
        }
    }
    cout << res;
    delete[] arr;
}