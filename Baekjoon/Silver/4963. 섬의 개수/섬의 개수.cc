#include <iostream>
#include <vector>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void initv(vector<vector<int> > &v, int h, int w)
{
	int num;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> num;
			v[i][j] = num;
		}
	}
}
void dfs(vector<vector<int> > v, vector<vector<bool> > &visited, int h, int w, int max_h, int max_w)
{
	int dfs_h, dfs_w;
	int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

	for (int i = 0; i < 8; i++)
	{
		dfs_h = h + dy[i];
		dfs_w = w + dx[i];
		if(dfs_h < 0 || dfs_w < 0 || dfs_h >= max_h || dfs_w >= max_w)
			continue;
		else if(v[dfs_h][dfs_w] == 1 && visited[dfs_h][dfs_w] == false)
		{
			visited[dfs_h][dfs_w] = true;
			dfs(v, visited, dfs_h, dfs_w, max_h, max_w);
		}
	}
}

int main()
{
	fast;
	int w, h, res = 0;
	vector<int> answer;
	vector<vector<int> > v;
	vector<vector<bool> > visited;
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		res = 0;
		v.resize(h, vector<int>(w));
		visited.resize(h, vector<bool>(w, false));
		initv(v, h, w);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] == false && v[i][j] == 1)
				{
					visited[i][j] = true;
					res++;
					dfs(v, visited, i, j, h, w);
				}
			}
		}
		if (w != 0 && h != 0)
			cout << res << '\n';
		v.clear();
		visited.clear();
	}
}
