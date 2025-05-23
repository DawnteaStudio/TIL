#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;
    int arr[1001];
    arr[1] = 1;
    arr[2] = 2;

    if (n == 1 || n == 2)
        cout << arr[n];
    else
    {
        for (int i = 3; i <= n; i++)
            arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
        cout << arr[n];
    }
}