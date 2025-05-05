#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, f, s, res = 0;
    cin >> n;

    vector<int> dp(n + 1, 0);
    vector<pair<int, int> > vec;
    for (int i = 0; i < n; i++)
    {
        cin >> f >> s;
        vec.push_back(make_pair(f, s));
    }

    for (int i = 0; i < n; i++)
    {
        if (dp[i] > res)
            res = dp[i];
        else
            dp[i] = res;
        if (i + vec[i].first > n)
            continue;
        if (dp[i] + vec[i].second > dp[i + vec[i].first])
            dp[i + vec[i].first] = dp[i] + vec[i].second;
    }
    if (dp[n] > res)
        res = dp[n];
    else
        dp[n] = res;
    cout << dp[n];
}
