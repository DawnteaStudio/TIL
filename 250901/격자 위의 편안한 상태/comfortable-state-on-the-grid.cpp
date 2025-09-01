#include <iostream>

using namespace std;

int N, M;
int field[101][101];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };


int main() {
    cin >> N >> M;

    int r, c;
    for (int i = 0; i < M; i++) {
        cin >> r >> c;
        field[r][c] = 1;
        int tmp = 0;
        for (int j = 0; j < 4; j++) {
            int y = r + dy[j];
            int x = c + dx[j];

            if (y < 1 || x < 1 || y > N || x > N)
                continue;
            if (field[y][x] == 1)
                tmp++;
        }
        if (tmp == 3)
            cout << 1;
        else
            cout << 0;
        cout << '\n';
    }
    // Please write your code here.
    return 0;
}