#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t;
    cin >> t;
    int arr[101];

    while (1)
    {
        for (int i = 0; i < t; i++)
            cin >> arr[i];
        for (int i = t - 1; i >= 0; i--)
            cout << arr[i] << '\n';
        cout << 0 << '\n';
        cin >> t;
        if (t == 0)
            break;
    }
}
