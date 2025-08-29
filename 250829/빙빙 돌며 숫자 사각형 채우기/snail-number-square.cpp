#include <iostream>

using namespace std;

int n, m;
int v = 1;
int arr[100][100];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int dir;

int main() {
    cin >> n >> m;

    int y = 0, x = -1;

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            y += dy[dir];
            x += dx[dir];
            if (y < 0 || x < 0 || y >= n || x >= m || arr[y][x] > 0) {
                y -= dy[dir];
                x -= dx[dir];
                dir++;
                dir %= 4;
                y += dy[dir];
                x += dx[dir];
            }
            arr[y][x] = v++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <m; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
    return 0;
}