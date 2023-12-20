#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dp[100000][2];
int main()
{
    int T, N, num, res;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N;
        res = 0;
        vector<pair<int, int>> v(N);
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            if (j % 2 == 0)
                v[j].first = num;
            else
                v[j].second = num;
        }
        for (int j = 0; j < N; j++)
        {
            cin >> num;
            if (j % 2 == 0)
                v[j].second = num;
            else
                v[j].first = num;
        }
        for (int j = 0; j < N; j++)
        {
            if (j == 0)
            {
                dp[0][0] = v[j].first;
                dp[0][1] = v[j].second;
            }
            else if (j == 1)
            {
                dp[1][0] = v[j].first + v[j - 1].first;
                dp[1][1] = v[j].second + v[j - 1].second;
            }
            else
            {
                dp[j][0] = v[j].first + dp[j - 1][0] > v[j].first + dp[j - 2][1] ? v[j].first + dp[j - 1][0] : v[j].first + dp[j - 2][1];
                dp[j][1] = v[j].second + dp[j - 1][1] > v[j].second + dp[j - 2][0] ? v[j].second + dp[j - 1][1] : v[j].second + dp[j - 2][0];
            }
        }
        res = dp[N - 1][0] > dp[N - 1][1] ? dp[N - 1][0] : dp[N - 1][1];
        cout << res << '\n';
    }
}
