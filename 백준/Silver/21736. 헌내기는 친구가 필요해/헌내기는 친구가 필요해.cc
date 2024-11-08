#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	fast;
	int n, m, res = 0;
	cin >> n >> m;
	int y = -1, x;
	vector<string> vec(n);
	vector<vector<bool> > visitied(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		if (y == -1)
			for (int j = 0; j < m; j++)
			{
				if (vec[i][j] == 'I') {
					y = i, x = j; break;
				}
			}
	}

	queue<pair<int, int> > q;
	visitied[y][x] = true;
	q.push(make_pair(y, x));
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int new_y = y + dy[i];
			int new_x = x + dx[i];

			if (new_y < 0 || new_x < 0 || new_y >= n || new_x >= m)
				continue;
			if (visitied[new_y][new_x] == false && vec[new_y][new_x] != 'X')
			{
				visitied[new_y][new_x] = true;
				if (vec[new_y][new_x] == 'P')
					res++;
				q.push(make_pair(new_y, new_x));
			}
		}
	}
	if (res)
		cout << res;
	else
		cout << "TT";
}
