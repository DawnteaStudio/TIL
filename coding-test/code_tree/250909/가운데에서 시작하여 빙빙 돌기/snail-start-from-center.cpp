#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int dir, n;
int grid[100][100];
int visited[100][100];

bool validRange(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= n)
        return false;
    if (visited[y][x])
        return false;
    return true;
}

int main() {
	fast;
    cin >> n;
    int v = 1;

    int y = n / 2 , x = n / 2;
    while (true) {
        bool flag = false;
        grid[y][x] = v++;
        visited[y][x] = 1;
        int cnt = 0;

        while (true) {
            int tmp_y = y + dy[dir];
            int tmp_x = x + dx[dir];
            if (validRange(tmp_y, tmp_x)) {
                dir = (dir + 1) % 4;
                y = tmp_y;
                x = tmp_x;
                break;
            }
            cnt++;
            dir = (dir - 1 + 4) % 4;
            if (cnt == 4)
                break;
        }
        if (cnt == 4)
            break;
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }

  
}
