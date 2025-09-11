#include <iostream>
#include <string>

using namespace std;

int N, M, res;
string arr[50];
int dy[4] = { 0, 1, 1, 1 };
int dx[4] = { 1, 1, 0, -1 };

void solve(int y, int x) {

    for (int i = 0; i < 4; i++) {
        string tmp = "";
        tmp += arr[y][x];
        int new_y = y;
        int new_x = x;

        for (int j = 1; j < 3; j++) {
            new_y += dy[i];
            new_x += dx[i];

            if (new_y < 0 || new_x < 0 || new_y >= N || new_x >= M)
				continue;
            tmp += arr[new_y][new_x];
        }
        if (tmp == "LEE" || tmp == "EEL") {
            res++;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Please write your code here.

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] != 'L' && arr[i][j] != 'E')
                continue;
            solve(i, j);
        }
    }

    cout << res;
    return 0;
}