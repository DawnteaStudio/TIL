#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    fast;
    int n;
    cin >> n;
    vector<vector<bool> > m(100, vector<bool>(100, false));

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        for (int row = y; row < y + 10; row++) {
            if (row > 100)
                continue;
            for (int col = x; col < x + 10; col++) {
                if (col > 100)
                    continue;
                m[row][col] = true;
            }
        }
    }

    int len = 0;
    for (int row = 0; row < 100; row++) {
        for (int col = 0; col < 100; col++) {
            if (m[row][col] == false)
                continue;
            int new_y, new_x;
            for (int i = 0; i < 4; i++) {
                new_y = row + dy[i];
                new_x = col + dx[i];

                if (new_y < 0 || new_y >= 100 || new_x < 0 || new_x >= 100)
                    len++;
                else if (m[new_y][new_x] == false)
                    len++;
            }
        }
    }
    cout << len;
}
