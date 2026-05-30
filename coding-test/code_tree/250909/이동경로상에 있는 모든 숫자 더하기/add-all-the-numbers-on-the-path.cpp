#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int dir, n, t, res;
int grid[100][100];

bool validRange(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= n)
        return false;
    return true;
}

int main() {
	fast;
    string cmd;
    cin >> n >> t >> cmd;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    int y = n / 2, x = n / 2;

    res += grid[y][x];
    for (int i = 0; i < t; i++) {
        if (cmd[i] == 'R')
            dir = (dir + 1) % 4;
        else if (cmd[i] == 'L')
            dir = (dir - 1 + 4) % 4;
        else {
            int new_y = y + dy[dir];
            int new_x = x + dx[dir];
            if (validRange(new_y, new_x)) {
                y = new_y;
                x = new_x;
                res += grid[y][x];
            }
        }
    }
    cout << res;
}
