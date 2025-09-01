#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int total;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

struct elem {
    int v;
    int drown = 0;
};

elem arr[301][301];

int main() {
    fast;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > pro; // 농작물 좌표
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j].v;
            if (arr[i][j].v > 0) {
                pro.push_back({ i, j });
                total++;
            }
        }
    }

    for (int i = 0; i < total; i++) {
        int tmp = 0;

        for (int j = 0; j < 4; j++) {
            int new_y = pro[i].first + dy[j];
            int new_x = pro[i].second + dx[j];

            if (new_y < 0 || new_x < 0 || new_y >= n || new_x >= m)
                continue;
            if (arr[new_y][new_x].v == 0)
                tmp++;
        }
        arr[pro[i].first][pro[i].second].drown = tmp;
    }

    int year = 0;
    int size = pro.size();
    while (total > 1) {
        vector<pair<int, int> > lazy;
        vector<vector<int> > visited(n, vector<int>(m, 0));
        for (int i = 0; i < size; i++) {
            int y = pro[i].first;
            int x = pro[i].second;

            if (arr[y][x].v <= 0)
                continue;
            arr[y][x].v -= arr[y][x].drown;
            if (arr[y][x].v <= 0) {
                total--;
                for (int j = 0; j < 4; j++) {
                    int new_y = y + dy[j];
                    int new_x = x + dx[j];

                    if (new_y < 0 || new_x < 0 || new_y >= n || new_x >= m)
                        continue;
                    if (arr[new_y][new_x].v > 0)
                        lazy.push_back({ new_y, new_x });
                }
            }
        }
        int lazy_size = lazy.size();
        for (int j = 0; j < lazy_size; j++) {
            int y = lazy[j].first;
            int x = lazy[j].second;
            arr[y][x].drown++;
        }
        year++;
        if (total <= 1)
            break;
        int cnt = 0;
        int y, x;

        for (int i = 0; i < size; i++) {
            y = pro[i].first;
            x = pro[i].second;
            if (arr[y][x].v > 0)
                break;
        }

        stack<pair<int, int> > s;
        visited[y][x] = 1;
        s.push({ y, x });

        while (!s.empty()) {
            y = s.top().first;
            x = s.top().second;
            s.pop();
            cnt++;

            for (int i = 0; i < 4; i++) {
                int new_y = y + dy[i];
                int new_x = x + dx[i];

                if (new_y < 0 || new_x < 0 || new_y >= n || new_x >= m)
                    continue;
                if (visited[new_y][new_x] == 1 || arr[new_y][new_x].v <= 0)
                    continue;
                visited[new_y][new_x] = 1;
                s.push({ new_y, new_x });
            }

        }
        if (cnt != total) {
            cout << year;
            return 0;
        }
    }
    cout << 0;
}
