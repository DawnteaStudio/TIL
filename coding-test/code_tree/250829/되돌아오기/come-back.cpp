#include <iostream>

using namespace std;

int N;
char dir;
int dist;
int y, x;
int d;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    cin >> N;
    int res = 0;

    for (int i = 0; i < N; i++) {
        cin >> dir >> dist;
        if (dir == 'E')
            d = 1;
        else if (dir == 'S')
            d = 2;
        else if (dir == 'W')
            d = 3;
        else
            d = 0;

        while (dist--) {
            y += dy[d];
            x += dx[d];
            res++;
            if (y == 0 && x == 0) {
                cout << res;
                return 0;
            }
        }
    }
    cout << -1;

    // Please write your code here.

    return 0;
}