#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
    cin >> n >> m;

    if (n <= m)
        cout << 2 * n - 1;
    else
        cout << 2 * m + 1;
}
