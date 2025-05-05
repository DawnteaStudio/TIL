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
    int n, m;
    cin >> n >> m;
    vector<vector<int> > vec(n, vector<int>(m));
    vector<vector<int> > res(n, vector<int>(m, -1));

    int start_x, start_y;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
            if (vec[i][j] == 2)
            {
                start_y = i;
                start_x = j;
                res[i][j] = 0;
            }
            else if (vec[i][j] == 0)
                res[i][j] = 0;
        }
    }

    queue<pair<int, int> > q;
    q.push(make_pair(start_y, start_x));
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        int cost = res[y][x];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int new_y = y + dy[i];
            int new_x = x + dx[i];

            if (new_y < 0 || new_x < 0 || new_y >= n || new_x >= m)
                continue;
            if (vec[new_y][new_x] == 0)
                res[new_y][new_x] = 0;
            else if (res[new_y][new_x] == -1 || res[new_y][new_x] > cost + 1)
            {
                res[new_y][new_x] = cost + 1;
                q.push(make_pair(new_y, new_x));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << res[i][j] << " ";
        cout << '\n';
    }
}
