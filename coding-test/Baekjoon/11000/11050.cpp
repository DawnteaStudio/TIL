#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, k;
    cin >> n >> k;

    int res = 1;
    int cnt = 1;
    for (int i = n; cnt <= k; n--, cnt++)
    {
        res *= n;
        res /= cnt;
    }
    cout << res;
}