#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    int n, size;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> size;
        vector<string> v(size);
        vector<vector<int> > dp(size, vector<int>(size, 99999));
        for (int j = 0; j < size; j++) {
                cin >> v[j];
        }
        dp[0][0] = 0;
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int new_y = y + dy[j];
                int new_x = x + dx[j];

                if (new_y >= size || new_x >= size || new_x < 0 || new_y < 0)
                    continue;
                if (dp[new_y][new_x] > dp[y][x] + (int)(v[new_y][new_x] - '0')) {
                    dp[new_y][new_x] = dp[y][x] + (int)(v[new_y][new_x] - '0');
                    q.push(make_pair(new_y, new_x));
                }
            }
        }
        cout << "#" << i << " " << dp[size - 1][size - 1] << '\n';
    }
}