#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int schedule[1002][2];
int dp[1002];
int N;

int main()
{
    fast;
    int days, revenue, res = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> days >> revenue;
        schedule[i][0] = days;
        schedule[i][1] = revenue;
    }
    for (int i = 1; i <= N + 1; i++)
    {
        if (res < dp[i])
            res = dp[i];
        if (schedule[i][0] + i > N + 1)
            continue;
        if (schedule[i][1] + res > dp[schedule[i][0] + i])
            dp[schedule[i][0] + i] = schedule[i][1] + res;
    }
    cout << res;
}
