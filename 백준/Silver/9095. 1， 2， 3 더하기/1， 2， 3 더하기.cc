#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int arr[11];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    for (int i = 3; i < 11; i++)
        arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
    int T, n;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << arr[n - 1] << '\n';
    }
}

