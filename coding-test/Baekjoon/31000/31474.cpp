#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    int size = n / 2;
    vector<long long> dp(size + 1);
    dp[1] = 1;
    for (int i = 2; i <= size; i++) {
        dp[i] = dp[i - 1] * (i * 2 - 1);
    }
    cout << dp[size];
}