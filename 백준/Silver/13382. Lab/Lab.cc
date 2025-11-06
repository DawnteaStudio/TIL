#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int t, m;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> m;
        vector<double> vec(m);
        vector<double> dp(m, 0);
        for (int j = 0; j < m; j++)
            cin >> vec[j];
        for (int j = 0; j < m; j++) {
            double tmp = 0;
            for (int k = j - 3; k >= j - 5; k--) {
                if (k < 0)
                    continue;
                if (tmp < dp[k])
                    tmp = dp[k];
            }
            dp[j] = tmp + vec[j];
        }
        double res = 0;
        for (int j = m - 1; j >= m - 3; j--) {
            if (dp[j] > res)
                res = dp[j];
        }
        // for (int j = 0; j < m; j++)
        //     cout << dp[j] << " ";
        // cout << '\n';

        res = round(res * 10);
        res /= 10;
        cout << res << '\n';
    }
}
