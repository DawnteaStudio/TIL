#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dp[101][10];

int main()
{
    int N, res;
    cin >> N;

    if (N == 1)
    {
        cout << "9" << '\n';
        return 0;
    }
    for (int i = 1; i < 10; i++)
        dp[1][i] = 1;
    res = 0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
            dp[i][j] %= 1000000000;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        res += dp[N][i];
        res %= 1000000000;
    }
    cout << res;
}
