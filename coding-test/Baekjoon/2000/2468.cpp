#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res;
int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void    find_value(vector<vector <int>> v, vector<vector <bool>> visited, int height)
{
    int tmp = 0;
    int new_x, new_y;
    queue<pair<int, int> > q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] > height && visited[i][j] == false)
            {
                visited[i][j] = true;
                tmp++;
                q.push({i, j});
            }
            while (!q.empty())
            {
                pair<int, int> tmp = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    new_y = tmp.first + dy[k];
                    new_x = tmp.second + dx[k];
                    if (new_y < 0 || new_x < 0 || new_y >= n || new_x >= n)
                        continue;
                    if (v[new_y][new_x] > height && visited[new_y][new_x] == false)
                    {
                        visited[new_y][new_x] = true;
                        q.push({new_y, new_x});
                    }
                    else if (visited[new_y][new_x] == false)
                        visited[new_y][new_x] = true;
                }
            }
        }
    }
    if (tmp > res)
        res = tmp;
}

int main()
{
    fast;

    cin >> n;
    vector<vector <int>> v(n, vector<int>(n));
    vector<vector <bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }

    for (int i = 1; i <= 100; i++)
        find_value(v, visited, i);
    if (res == 0)
        res++;
    cout << res;
}
