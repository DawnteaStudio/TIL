#include <iostream>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, res = 0;
	cin >> n;
	vector<int> dp(n + 1, 0);
	vector<int> pows;

	int end = sqrt(n);
	for (int i = 1; i <= end; i++)
	{
		dp[i * i] = 1;
		pows.push_back(i * i);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < pows.size(); j++)
		{
			if (i + pows[j] <= n)
			{
				if (dp[i + pows[j]] > dp[i] + 1 || dp[i + pows[j]] == 0)
					dp[i + pows[j]] = dp[i] + 1;
			}
			else
				break;
		}
	}
	cout << dp[n];
}