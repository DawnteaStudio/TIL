#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

int n, res;
char grid[1000][1000];
int k;
int dir;

int main() {
	fast;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> k;
    dir = (k - 1) / n;

    int y, x;
    switch (dir) {
        case  0:
            y = 0;
            x = k - 1;
            break;
        case 1:
            x = n - 1;
            y = (k - 1) % n;
            break;
        case 2:
            y = n - 1;
            x = n - 1 - (k % n);
            break;
        case 3:
            x = 0;
            y = n - 1 - (k % n);
            break;
        default:
            break;
    }
    while (true) {
        res++;
        if (grid[y][x] == '/') {
            if (dir % 2 == 0)
                dir++;
            else
                dir--;
        }
        else {
            if (dir % 2 == 0)
                dir = (dir - 1 + 4) % 4;
            else
                dir = (dir + 1) % 4;
        }
        y += dy[dir];
        x += dx[dir];
        if (y < 0 || x < 0 || y >= n || x >= n)
            break;
    }
    cout << res;
}
