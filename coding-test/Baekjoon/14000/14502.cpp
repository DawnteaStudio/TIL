#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m, res;
pair<int, int> dot1, dot2, dot3;
vector<pair<int, int> > virus;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void    get_res(vector<vector<int> > vec)
{
    int space = 0;
    vec[dot1.first][dot1.second] = 1;
    vec[dot2.first][dot2.second] = 1;
    vec[dot3.first][dot3.second] = 1;

    queue<pair<int, int> > q;
    for (int i = 0; i < virus.size(); i++)
        q.push(virus[i]);
    while (!q.empty())
    {
        int new_x, new_y;
        pair<int, int> tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            new_y = tmp.first + dy[i];
            new_x = tmp.second + dx[i];
            if (new_y < 0 || new_x < 0 || new_y >= n || new_x >= m)
                continue;
            if (vec[new_y][new_x] == 0)
            {
                vec[new_y][new_x] = 2;
                q.push(make_pair(new_y, new_x));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == 0)
                space++;
        }
    }
    if (res < space)
        res = space;
}

void    solve(int y, int x, vector<vector<int> >&vec, int depth)
{
    if (depth == 3)
        get_res(vec);
    else
    {
        for (int i = y; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == y && j <= x && depth != 0)
                    continue;
                if (vec[i][j] == 0)
                {
                    if (depth == 0)
                        dot1 = make_pair(i , j);
                    else if (depth == 1)
                        dot2 = make_pair(i, j);
                    else
                        dot3 = make_pair(i, j);
                    solve(i, j, vec, depth + 1);
                }
            }
        }
    }
}

int main() {
    fast;
    cin >> n >> m;
    vector<vector<int> > vec(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
            if (vec[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }

    solve(0, 0, vec, 0);
    cout << res;
}
