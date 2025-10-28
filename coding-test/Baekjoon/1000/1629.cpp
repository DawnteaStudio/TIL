#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long solve(long long a, long long b, long long c)
{
    if (b == 0)
        return 1 % c;
    long long half = solve(a, b / 2, c);
    long long mod = (half * half) % c;
    if (b & 1)
        mod = (mod * (a % c)) % c;
    return mod;
}

int main()
{
    fast;
    long long a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c);
}
