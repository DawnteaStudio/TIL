#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res = 0, cnt = 1;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i + 1])
            cnt++;
        else
        {
            res += cnt;
            cnt = 1;
        }
    }
    cout << res;
}