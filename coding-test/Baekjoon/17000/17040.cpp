#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m;
	cin >> n >> m;

	int node1, node2;
	vector<vector<int> > v(n + 1);
	vector<vector<int> > color(5);

	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		int tmp = max(node1, node2);

		node1 = min(node1, node2);
		node2 = tmp;

		v[node1].push_back(node2);
		v[node2].push_back(node1);
	}

	for (int i = 1; i <= n; i++) {
		bool done = false;
		if (v[i].empty()) {
			color[1].push_back(i);
			continue;
		}
		for (int j = 1; j <= 4; j++) {
			int len = v[i].size();
			for (int k = 0; k < len; k++) {
				if (find(color[j].begin(), color[j].end(), v[i][k]) != color[j].end()) {
					break;
				}
				if (k == len - 1) {
					color[j].push_back(i);
					done = true;
				}
			}
			if (done)
				break;
		}
	}

	vector<int> res(n + 1);
	for (int i = 1; i <= 4; i++) {
		int s = color[i].size();
		for (int j = 0; j < s; j++) {
			res[color[i][j]] = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i];
	}
}
