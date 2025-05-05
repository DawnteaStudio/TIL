#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int N, chance, tmp, cnt = 0;
    cin >> N >> chance;
    int *arr = new int[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                cnt++;
                if (cnt == chance)
                {
                    cout << arr[j] << ' ' << arr[j+1];
                    break;
                }
            }
        }
    }
    if (cnt < chance)
        cout << -1;
    delete[] arr;
}