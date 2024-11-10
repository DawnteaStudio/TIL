#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, m, res = -1, answer;
	cin >> n >> m;

	vector<vector<int> > vec(n + 1, vector<int>(n + 1, 100));
	for (int i = 1; i <= n; i++)
		vec[i][i] = 0;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		vec[a][b] = 1;
		vec[b][a] = 1;
	}
	for (int mid = 1; mid <= n; mid++)
	{
		for (int start = 1; start <= n; start++)
		{
			if (mid == start)
				continue;
			for (int end = 1; end <= n; end++)
			{
				if (end == start || end == mid)
					continue;
				vec[start][end] = (vec[start][end] > vec[start][mid] + vec[mid][end] ? vec[start][mid] + vec[mid][end] : vec[start][end]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for (int j = 1; j <= n; j++)
			tmp += vec[i][j];
		if (res == -1 || res > tmp)
		{
			res = tmp;
			answer = i;
		}
	}
	cout << answer;
}
