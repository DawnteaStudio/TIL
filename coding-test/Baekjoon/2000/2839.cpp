#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n;
    cin >> n;

    int arr[n + 1];
    for (int i = 0; i < n + 1; i++)
        arr[i] = 0;
    
    arr[3] = 1;
    if (n >= 5)
        arr[5] = 1;
    for (int i = 3; i <= n; i++)
    {
        int tmp = 0;
        if (arr[i - 3] != 0)
            tmp = arr[i - 3] + 1;
        if (i >= 5 && arr[i - 5] != 0)
        {
            if (tmp != 0)
            {
                if (arr[i - 5] + 1 < tmp)
                    tmp = arr[i - 5] + 1;
            }
            else
                tmp = arr[i - 5] + 1;
        }
        if (tmp != 0)
            arr[i] = tmp;
    }
    if (arr[n] == 0)
        cout << -1;
    else
        cout << arr[n];
}
