#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res = 1, cnt = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        res *= i;
        while (res % 10 == 0)
        {
            cnt++;
            res /= 10;
        }
        if (i < 10)
            res %= 100;
        else if (i < 100)
            res %= 10000;
        else
            res %= 1000000;
    }
    cout << cnt;
}