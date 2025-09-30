#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int visited[10];
int res;
int grid[3][3];


void solve(int y, int x, int depth)
{
	if (depth == 9) {
		res++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int new_y = y + dy[i];
		int new_x = x + dx[i];

		if (new_y < 0 || new_x < 0 || new_y >= 3 || new_x >= 3)
			continue;
		if (visited[grid[new_y][new_x]] == 1)
			continue;
		visited[grid[new_y][new_x]] = 1;
		solve(new_y, new_x, depth + 1);
		visited[grid[new_y][new_x]] = 0;
	}
}

int main() {
	fast;
    
	int k;
	cin >> k;
	visited[k] = 1;

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= 3; j++)
			grid[i][j - 1] = 3 * i + j;
	}

	int y, x;
	y = (k - 1) / 3;
	x = (k - 1) % 3;
	solve(y, x, 1);
	cout << res;
}
