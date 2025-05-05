#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int solve(int a, int b, int c, int d, int l)
{
    return max(a * (int)pow(l - b, 2) + c, d);
}

int main()
{
    fast;
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;

    int cnt = 0, r, l;
    for (int i = 0; i < n; i++) {
        cin >> r >> l;
        if (r == solve(a, b, c, d, l))
            cnt++;
    }
    cout << cnt;
}