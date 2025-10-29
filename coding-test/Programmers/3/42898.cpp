#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));


    int pud = puddles.size();
    for (int i = 0; i < pud; i++) {
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    for (int i = 1; i <= n; i++) {
        if (dp[i][1] == -1)
            break;
        dp[i][1] = 1;
    }
    for (int j = 1; j <= m; j++) {
        if (dp[1][j] == -1)
            break;
        dp[1][j] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (dp[i][j] == -1)
                continue;
            int up = dp[i - 1][j];
            int left = dp[i][j - 1];
            if (up < 0)
                up = 0;
            if (left < 0)
                left = 0;
            dp[i][j] = (up + left) % MOD;
        }
    }
    return dp[n][m];
}