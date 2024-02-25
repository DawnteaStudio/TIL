#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m, res, num;
    int start, end;
    cin >> n >> m;
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        arr[i] = arr[i - 1] + num;
    }
    for (int i = 0; i < m; i++)
    {
        res = 0;
        cin >> start >> end;
        res = arr[end] - arr[start - 1];
        cout << res << '\n';
    }
}

