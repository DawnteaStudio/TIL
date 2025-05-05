#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool check(int b, int c, int d)
{
    if (b + c + d < 55) return false;
    if ((double)b < 35.0 * 0.3) return false;
    if ((double)c < 25.0 * 0.3) return false;
    if ((double)d < 40.0 * 0.3) return false;
    return true;
}

int main()
{
    fast;
    int n; cin >> n;
    int a, b, c, d;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c >> d;

        cout << a << ' ' << b + c + d << ' ';
        if (check(b, c, d)) cout << "PASS\n";
        else cout << "FAIL\n";
    }
    return 0;
}