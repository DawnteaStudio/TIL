#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;
int schedule[1500002][2];
int dp[1500002];

int main()
{
    int days, revenue, res = 0;
    fast;
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
        if (i + schedule[i][0] > N + 1)
            continue;
        if (schedule[i][1] + res > dp[i + schedule[i][0]])
            dp[i + schedule[i][0]] = schedule[i][1] + res;
    }
    cout << res;
}
