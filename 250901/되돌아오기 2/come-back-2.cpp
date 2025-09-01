#include <iostream>
#include <string>

using namespace std;

string commands;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int dir;

int main() {
    cin >> commands;
    int len = commands.length();

    int y = 0, x = 0;
    for (int i = 0; i < len; i++) {
        if (commands[i] == 'F') {
            y += dy[dir];
            x += dx[dir];
            if (y == 0 && x == 0) {
                cout << i + 1;
                return 0;
            }
        }
        else if (commands[i] == 'R')
            dir = (dir + 1) % 4;
        else {
            dir--;
            if (dir < 0)
                dir = 3;
        }
    }

    // Please write your code here.
    cout << -1;
    return 0;
}