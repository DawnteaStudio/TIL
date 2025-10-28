#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {0, 1, 1, 1};
int dx[4] = {1, 1, 0, -1};

int main() {
	fast;
	int n, m;
	int blue = 0;
	int red = 0;
	cin >> n >> m;

	vector<vector<int> > vec(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> vec[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec[i][j] == 0)
				continue;
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];

				if (y < 0 || x < 0 || y >= n || x >= m)
					continue;
				if (vec[y][x] == 1) {
					if (k % 2 == 0)
						blue++;
					red++;
				}
			}
		}
	}
	cout << blue << " " << red;
}
