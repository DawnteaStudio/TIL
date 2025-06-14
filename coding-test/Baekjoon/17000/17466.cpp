#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    long long n, p;
    cin >> n >> p;
    long long res = 1;
    for (long long i = n; i > 0; i--)
        res = (res * i) % p;
    cout << res;
    return (0);
}