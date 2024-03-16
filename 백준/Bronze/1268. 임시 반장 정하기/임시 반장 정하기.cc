#include <iostream>
#include <vector>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void reset_visited(vector<bool> &visited)
{
	for (int i = 0; i < visited.size(); i++)
		visited[i] = false;
}

int main()
{
	fast;
	int n, tmp;
	pair<int, int> res;
	res.first = 0;
	res.second = 0;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(5));
	vector<bool> visited(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> v[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		tmp = 0;
		reset_visited(visited);
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (k == i)
					continue;
				if (v[i][j] == v[k][j] && visited[k] == false)
				{
					visited[k] = true;
					tmp++;
				}
			}
		}
		if (tmp > res.second)
		{
			res.first = i + 1;
			res.second = tmp;
		}
	}
	if (res.first == 0)
		cout << 1;
	else
		cout << res.first;
}
