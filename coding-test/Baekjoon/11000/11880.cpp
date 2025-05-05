#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t;
    cin >> t;
    int a, b, c;
    long long res, longest, other;

    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;
        if (a > b) longest = max(a, c);
        else longest = max(b, c);
        other = a + b + c - longest;
        res = longest * longest + other * other;
        cout << res << '\n';
    }
    return 0;
}