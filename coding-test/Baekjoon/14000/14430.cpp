#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[2] = {0, 1};
int dx[2] = {1, 0};

int main() {
	fast;
	int n, m;
	cin >> n >> m;

	int res = 0;
	vector<vector<int> > vec(n, vector<int>(m, -1));
	vector<vector<int> > dist(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> vec[i][j];
	
	queue<pair<int, int> > q;
	if (vec[0][0] == 1)
		dist[0][0] = 1;
	else
		dist[0][0] = 0;
	q.push({0, 0});

	while (!q.empty()) {
		pair<int, int> node = q.front();
		if (dist[node.first][node.second] > res)
			res = dist[node.first][node.second];
		q.pop();

		for (int i = 0; i < 2; i++) {
			int new_y = node.first + dy[i];
			int new_x = node.second + dx[i];

			if (new_x >= m || new_y >= n)
				continue;
			if (dist[new_y][new_x] > dist[node.first][node.second])
				continue;

			if (vec[new_y][new_x] == 1) {
				if (dist[node.first][node.second] + 1 > dist[new_y][new_x])
					dist[new_y][new_x] = dist[node.first][node.second] + 1;
			}
			else
				dist[new_y][new_x] = dist[node.first][node.second];
			q.push({new_y, new_x});
		}
	}
	cout << res;
}
