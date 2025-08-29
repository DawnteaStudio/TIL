#include <iostream>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int dir, y, x;

string dirs;

int main() {
    cin >> dirs;

    // Please write your code here.
    int len = dirs.length();

    for (int i = 0; i < len; i++) {
        if (dirs[i] == 'F') {
            y += dy[dir];
            x += dx[dir];
        }
        else if (dirs[i] == 'R')
            dir = (dir + 1) % 4;
        else {
            dir -= 1;
            if (dir == -1)
                dir = 3;
        }
    }
    cout << y << " " << x;
    return 0;
}