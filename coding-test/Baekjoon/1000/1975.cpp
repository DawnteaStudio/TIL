#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_zero(int b, int n)
{
    int zero = 0, tmp;
    while (n)
    {
        tmp = n % b;
        if (tmp == 0)
            zero++;
        else
            break;
        n /= b;
    }
    return zero;
}

int main()
{
    fast;
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        int cnt = 0;
        for (int j = 2; j <= n; j++)
            cnt += find_zero(j, n);
        cout << cnt << '\n';
    }
}