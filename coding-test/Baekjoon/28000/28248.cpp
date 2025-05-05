#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b, res = 0;
    cin >> a >> b;
    res = (a * 50) - (b * 10);
    if (a > b)
        res += 500;
    cout << res;
}