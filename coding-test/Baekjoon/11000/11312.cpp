#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long   solve(long long n)
{
    long long res = 1;
    long long   inc = 3;

    for (int i = 1; i < n; i++)
    {
        res += inc;
        inc += 2;
    }
    return res;
}

int main()
{
    fast;
    int n;
    long long a, b, res;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        res = 1;

        res = solve(a / b);
        cout << res << '\n';
    }
}
