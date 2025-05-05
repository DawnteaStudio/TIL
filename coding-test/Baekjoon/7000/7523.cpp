#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        long long n, m, res;
        cin >> n >> m;

        res = (m + n) * ((m - n) / 2 + 1);
        if ((m - n) % 2 == 0)
            res -= (m + n) / 2;
        cout << "Scenario #" << i << ":\n";
        cout << res << '\n' << '\n';
    }
}
