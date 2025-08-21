#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void dfs(vector<vector<int> > &vec, vector<vector<int> > &dp, int now, int pre)
{
	int size = vec[now].size();
	dp[now][0] = 0;
	dp[now][1] = 1;

	for (int i = 0; i < size; i++) {
		if (vec[now][i] == pre)
			continue;
		int node = vec[now][i];

		dfs(vec, dp, node, now);

		dp[now][0] += dp[node][1];
		dp[now][1] += min(dp[node][0], dp[node][1]);
	}
}

int main(void) {
	fast;

	int n;
	cin >> n;

	vector<vector<int> > vec(n + 1);
	vector<vector<int> > dp(n + 1, vector<int>(2));
	int a, b;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(vec, dp, 1, 0);
	cout << min(dp[1][0], dp[1][1]);
}
