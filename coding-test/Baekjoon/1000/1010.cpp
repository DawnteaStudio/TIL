#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        long long res = 1;
        for (int i = 1; i <= n; i++) {
            res *= (m - i + 1);
            res /= i;
        }

        cout << res << '\n';
    }
}
