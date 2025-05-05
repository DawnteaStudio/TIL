#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    long long x, res = 0;
    long long layer = 1;
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
        layer = layer * 2 + 3;
    while (x > 0)
    {
        if (x > layer / 2 + 1)
        {
            res += ((layer / 2) / 2) + 1;
            x -= (layer / 2) + 1;
            layer = layer / 2;
            if (x == layer)
                x--;
            layer--;
        }
        else if (x == layer / 2 + 1)
        {
            res += ((layer / 2) / 2) + 1;
            x -= layer / 2 + 1;
        }
        else
        {
            layer = layer / 2 - 1;
            x--;
        }
    }
    cout << res;
}