#include <iostream>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fast;
    int n, m;
    int res = 0, tmp;
    cin >> n >> m;

    vector<vector<int> > a(n, vector<int>(n));
    vector<vector<int> > b(n, vector<int>(n));
    vector<int> dp(n, 0);
    vector<int> dream(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> dream[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp = abs(a[j][i] - b[j][i]);
            if (tmp > dp[i])
                dp[i] = tmp;
        }
    }
    for (int i = 0; i < m; i++) {
        res += dp[dream[i] - 1];
    }
    cout << res;
}
