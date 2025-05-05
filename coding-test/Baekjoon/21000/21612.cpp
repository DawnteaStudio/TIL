#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    int res = 5 * n - 400;
    cout << res << '\n';
    if (res < 100)
        cout << 1 << '\n';
    else if (res == 100)
        cout << 0 << '\n';
    else
        cout << -1 << '\n';
}