#include <iostream>

using namespace std;

int n, t, dir;
int r, c;
char d;

int dy[4] = {0, -1, 1, 0};
int dx[4] = {1, 0, 0, -1};

int main() {
    cin >> n >> t;
    cin >> r >> c >> d;

    if (d == 'U')
        dir = 1;
    else if (d == 'D')
        dir = 2;
    else if (d == 'L')
        dir = 3;
    // Please write your code here.

    t %= 2 * n;
    for (int i = 0; i < t; i++) {
        r += dy[dir];
        c += dx[dir];

        if (r < 1 || c < 1 || c > n || r > n) {
            r -= dy[dir];
            c -= dx[dir];
            dir = 3 - dir;
        }
    }
    cout << r << " " << c;
    return 0;
}