#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    fast;
    int r, c;
    vector<vector<int> > vec(5, vector<int>(5));
    vector<vector<int> > step(5, vector<int>(5, 0));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cin >> vec[i][j];
    }

    cin >> r >> c;
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        int y, x;
        for (int i = 0; i < 4; i++) {
            y = node.first + dy[i];
            x = node.second + dx[i];

            if (y >= 5 || x >= 5 || y < 0 || x < 0)
                continue;
            if (step[y][x] == 0 || step[y][x] > step[node.first][node.second]) {
                if (vec[y][x] == 0) {
                    step[y][x] = step[node.first][node.second] + 1;
                    q.push(make_pair(y, x));
                }
                else if (vec[y][x] == 1) {
                    cout << step[node.first][node.second] + 1;
                    return 0;
                }
            }
        }
    }
    cout << -1;
}