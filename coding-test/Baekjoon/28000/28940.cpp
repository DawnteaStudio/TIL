#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int w, h, n, a, b, res = 0;
    cin >> w >> h >> n >> a >> b;

    if (w < a || h < b)
    {
        cout << -1;
        return 0;
    }
    while (n > 0)
    {
        n -= ((w/a) * (h/b));
        res++;
    }
    cout << res;
}
