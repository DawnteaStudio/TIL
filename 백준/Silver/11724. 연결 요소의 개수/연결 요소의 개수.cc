#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void	solve(vector<bool> &visited, vector<vector<int> > &vec, int start)
{
	for (int i = 0; i < vec[start].size(); i++)
	{
		if (visited[vec[start][i]] == false)
		{
			visited[vec[start][i]] = true;
			solve(visited, vec, vec[start][i]);
		}
	}
}

int main()
{
	fast;
	int n, m, cnt = 0;
	cin >> n >> m;
	vector<bool> visited(n + 1, false);
	vector<vector<int> > vec(n + 1);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == true)
			continue;
		visited[i] = true;
		cnt++;
		solve(visited, vec, i);
	}
	cout << cnt;
}
