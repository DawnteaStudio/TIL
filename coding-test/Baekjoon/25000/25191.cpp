#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, a, b, res = 0;
    cin >> n >> a >> b;

    res += ((a / 2) + b);
    if (res > n)
        res = n;
    cout << res;
}