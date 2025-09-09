#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
	fast;
	int n, m;
    while (true) {
		cin >> n >> m;
		if (n == 0)
			break;
		vector<string> field(n);
		vector<vector<int> > ans(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
			cin >> field[i];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] == '*')
					ans[i][j] = -1;
				else {
					for (int p = 0; p < 8; p++) {
						int new_i = i + dy[p];
						int new_j = j + dx[p];

						if (new_i < 0 || new_j < 0 || new_i >= n || new_j >= m)
							continue;
						if (field[new_i][new_j] == '*')
							ans[i][j]++;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ans[i][j] != -1)
					cout << ans[i][j];
				else
					cout << '*';
			}
			cout << '\n';
		}
	}
}
