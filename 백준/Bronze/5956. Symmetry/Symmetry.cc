#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int solve(int n, int m)
{
    if (n % 2 && m % 2) {
        return 1 + solve(n / 2, m / 2) * 4;
    }
    return 0;
}

int main()
{
    fast;
    int n, m, res;
    cin >> n >> m;

    res = solve(n, m);
    cout << res;
}
