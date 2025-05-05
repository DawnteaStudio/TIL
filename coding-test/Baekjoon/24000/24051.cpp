#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int N, chance, tmp, loc, cnt = 0;
    cin >> N >> chance;
    int *arr = new int[N];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 1; i < N; i++)
    {
        loc = i - 1;
        tmp = arr[i];

        while(0 <= loc && tmp < arr[loc])
        {
            arr[loc + 1] = arr[loc];
            cnt++;
            loc--;
            if (cnt == chance)
                cout << arr[loc + 1];
        }
        if (loc + 1 != i)
        {
            arr[loc + 1] = tmp;
            cnt++;
            if (cnt == chance)
                cout << arr[loc + 1];
        }
    }
    if (cnt < chance)
        cout << -1;
    delete[] arr;
}