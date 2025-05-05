#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int a, b, c, d, res;
    int e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int min_val = 100;
    if (a < min_val)
        min_val = a;
    if (b < min_val)
        min_val = b;
    if (c < min_val)
        min_val = c;
    if (d < min_val)
        min_val = d;
    res = a + b + c + d - min_val;
    min_val = 100;
    if (e < min_val)
        min_val = e;
    if (f < min_val)
        min_val = f;
    res += e + f - min_val;
    cout << res;
}
