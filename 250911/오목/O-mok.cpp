#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[20][20];

int dy[4] = { 0, 1, 1, 1 };
int dx[4] = { 1, 1, 0, -1 };

bool solve(int y, int x) {
	int v = arr[y][x];

	for (int i = 0; i < 4; i++) {
		int new_y = y;
		int new_x = x;
		for (int j = 1; j < 5; j++) {
			new_y += dy[i];
			new_x += dx[i];

			if (new_y < 1 || new_x < 1 || new_y > 19 || new_x > 19)
				break;
			if (arr[new_y][new_x] != v)
				break;
			if (j == 4) {
				cout << v << '\n' << (y + new_y) / 2 << " " << (x + new_x) / 2;
				return true;
			}
		}
	}
	return false;
}

int main() {
	fast;
    
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			if (arr[i][j] == 0)
				continue;
			else {
				if (solve(i, j))
					return 0;
			}
		}
	}
	cout << -1;
}
