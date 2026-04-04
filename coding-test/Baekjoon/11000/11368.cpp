#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	long long C, W, L, P;

    while (cin >> C >> W >> L >> P) {
        if (C == 0 && W == 0 && L == 0 && P == 0) {
            break;
        }

        if (C == 1) {
            cout << 1 << '\n';
            continue;
        }

        long long exp = W * L * P;
        long long ans = 1;

        while (exp--) {
            ans *= C;
        }

        cout << ans << '\n';
    }
}
