#include <iostream>

using namespace std;

int n, cnt;
int grid[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            for (int k = 0; k < 4; k++) {
                int x = j + dx[k];
                int y = i + dy[k];

                if (x < 0 || y < 0 || x >= n || y >= n)
                    continue;
                if (grid[y][x] == 1)
                    tmp++;
            }
            if (tmp >= 3)
                cnt++;
        }
    }

    // Please write your code here.
    cout << cnt;
    return 0;
}