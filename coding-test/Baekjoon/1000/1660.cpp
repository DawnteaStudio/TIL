#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int get_cnt(int layer)
{
    int res = 0;
    int cnt = 0;
    for (int i = 1; i <= layer; i++)
    {
        cnt += i;
        res += cnt;
    }
    return res;
}

int main() {
    fast;
    int n, layer = 1;
    cin >> n;

    vector<int> dp(n + 1);
    vector<int> possible;

    for (int i = 0; i <= n; i++)
        dp[i] = i;
    while (true)
    {
        int tmp = get_cnt(layer);
        if (tmp <= n)
            possible.push_back(tmp);
        else
            break;
        layer++;
    }
    int now = 0;
    int size = possible.size();
    for (int i = 1; i <= n; i++)
    {
        if (i == possible[now])
        {
            dp[i] = 1;
            if (now + 1 < size)
                now++;
        }
        else
        {
            for (int j = 0; j <= now; j++)
            {
                if (i >= possible[j])
                {
                    if (dp[i] > dp[i - possible[j]] + 1)
                        dp[i] = dp[i - possible[j]] + 1;
                }
                else
                    break;
            }
        }
    }
    cout << dp[n] << '\n';
}