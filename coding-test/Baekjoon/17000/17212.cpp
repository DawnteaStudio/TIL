#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int cost[4] = {1, 2, 5, 7};

int main()
{
    fast;
    int n;
    cin >> n;

    vector<vector<int> > dp(4, vector<int>(n + 1, 0));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= n; j++) {
            if (cost[i] > j) {
                if (i == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j];
            }
            else {
                if (i != 0)
                    dp[i][j] = min(dp[i][j - cost[i]] + 1, dp[i - 1][j]);
                else
                    dp[i][j] = dp[i][j - cost[i]] + 1;
            }
        }
    }
    cout << dp[3][n];
}
