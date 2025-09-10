#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

char grid[15][15];
int res;

int main() {
	fast;
    
	int n, m;
	cin >> n >> m;
	char now = grid[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];
	}

	for (int i = 1; i < n - 2; i++) {
		for (int j = 1; j < m - 2; j++) {
			if (now == grid[i][j])
				continue;
			for (int p = i + 1; p < n - 1; p++) {
				for (int q = j + 1; q < m - 1; q++) {
					if (grid[i][j] == grid[p][q])
						continue;
					res++;
				}
			}
		}
	}
	cout << res;
}
