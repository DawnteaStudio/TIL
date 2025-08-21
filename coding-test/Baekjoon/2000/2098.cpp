#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int total_mask = (1 << 16);
int n;
int _mask;
vector<vector<int> > vec;
vector<vector<int> > dp(16, vector<int>(total_mask, -1)); // [node][visit mask]

int solve(int node, int mask)
{
	int& memo = dp[node][mask];

	if (memo != -1)
		return memo;
	if (mask == _mask) {
		if (vec[node][0] == 0)
			return memo = 1000001;
		return memo = vec[node][0];
	}

	int best = 999999999;

	for (int i = 0; i < n; i++) {
		if (mask & (1 << i))
			continue;
		int cost = vec[node][i];
		if (cost == 0)
			continue;

		int next_mask = mask | (1 << i);
		int future = solve(i, next_mask);
		int total = cost + future;

		if (best > total)
			best = total;
	}

	return memo = best;
}


int main(void) {
	fast;

	cin >> n;


	vec.resize(n);
	for (int i = 0; i < n; i++)
		vec[i].resize(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> vec[i][j];
	}

	_mask = (1 << n) - 1;
	cout << solve(0, 1);;
}
