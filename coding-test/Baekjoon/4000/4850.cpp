#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    long long n, w, d, all;
    while (cin >> n) {
        cin >> w >> d >> all;

        long long cnt;
        if (n % 2 == 0)
            cnt = (1 + n) * (n / 2) - n;
        else
            cnt = (1 + n) * (n / 2) + ((1 + n) / 2) - n;

        long long res = (cnt * w - all) / d;
        if (res == 0)
            cout << n << '\n';
        else
            cout << res << '\n';
    }
}