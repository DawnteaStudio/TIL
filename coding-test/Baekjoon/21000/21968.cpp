#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long ft_pow(long long num, long long pos)
{
    long long res = 1;
    for (long long i = 0; i < pos; i++)
        res *= 3;
    return res;
}

int main() {
    fast;
    int n, pos;
    long long N, res, bit;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> N;
        pos = 0;
        res = 0;
        while (N > 0)
        {
            bit = N % 2;
            N /= 2;
            res += ft_pow(3, pos) * bit;
            pos++;
        }
        cout << res << '\n';
    }
}
