#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int a, b, c, d, min = 500, res;
    cin >> a >> b >> c >> d;
    res = a + b + c + d + 1;
    if (a < min)
        min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    if (d < min)
        min = d;
    cout << res - min;
}