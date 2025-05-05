#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	fast;
	int n, cnt = 1;
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		vector<vector<int> > vec(n, vector<int>(n));
		vector<vector<int> > dp(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> vec[i][j];
		}
		dp[0][0] = vec[0][0];
		queue<pair<int, int> > q;
		q.push(make_pair(0, 0));
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int new_y = y + dy[i];
				int new_x = x + dx[i];
				if (new_y < 0 || new_x < 0 || new_y >= n || new_x >= n)
					continue;
				if (dp[new_y][new_x] == -1 || dp[new_y][new_x] > vec[new_y][new_x] + dp[y][x])
				{
					dp[new_y][new_x] = vec[new_y][new_x] + dp[y][x];
					q.push(make_pair(new_y, new_x));
				}
			}
		}
		cout << "Problem " << cnt << ": " << dp[n - 1][n - 1] << '\n';
		cnt++;
	}
}