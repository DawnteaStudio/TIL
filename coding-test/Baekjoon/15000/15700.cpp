#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    unsigned long long n, m, res = 0;
    cin >> n >> m;

    if (n == 1 && m == 1)
        res = 0;
    else if (n % 2 == 0)
        res = (n / 2) * m;
    else if (m % 2 == 0)
        res = (m / 2) * n;
    else
        res = (n / 2) * m + (m / 2);
    cout << res;
}
