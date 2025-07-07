#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

const long long MOD = 1000000007;
const long long LIMIT = (1LL << 62);

int main()
{
    fast;
    int n;
    cin >> n;

    long long res = 1, tmp;
    for (int i = 0; i < n; i++)
    {
        res <<= 1;
        cin >> tmp;
        if (res < tmp)
        {
            cout << "error\n";
            return 0;
        }
        res -= tmp;
        if (res >= LIMIT)
        {
            res %= MOD;
            res += MOD * (((long long)1 << 61) / MOD);
        }
    }
    cout << res % MOD << "\n";
}