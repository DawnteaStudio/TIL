#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dp[501][501];
int graph[501][501];

int main()
{
    int N, tmp, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
            cin >> graph[i][j];
    }
    dp[1][0] = graph[1][0];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            tmp = dp[i][j] + graph[i + 1][j];
            if (dp[i + 1][j] < tmp)
                dp[i + 1][j] = tmp;
            tmp = dp[i][j] + graph[i + 1][j + 1];
            if (dp[i + 1][j + 1] < tmp)
                dp[i + 1][j + 1] = tmp;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dp[N][i] > res)
            res = dp[N][i];
    }
    cout << res;
}
