#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};
int dz[2] = {-1, 1};

struct pos {
    int x;
    int y;
    int z;
    int t;
};

pos make_pos(int y, int x, int z, int t)
{
    pos *res = new pos;

    res->y = y;
    res->x = x;
    res->z = z;
    res->t = t;
    return *res;
}

int main() {
    fast;
    int m, n, h, target = 0, res = 0;
    cin >> m >> n >> h;
    vector<vector<vector<int> > > vec(n, vector<vector<int> >(m, vector<int>(h)));
    vector<vector<vector<bool> > > visited(n, vector<vector<bool> >(m, vector<bool>(h, false)));

    queue<pos> q;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> vec[j][k][i];
                if (vec[j][k][i] == 0)
                    target++;
                else if (vec[j][k][i] == 1)
                {
                    q.push(make_pos(j, k, i, 0));
                    visited[j][k][i] = true;
                }
            }
        }
    }

    while (!q.empty())
    {
        pos tmp = q.front();
        q.pop();
        if (res < tmp.t)
            res = tmp.t;

        for (int i = 0; i < 4; i++)
        {
            int y = tmp.y + dy[i];
            int x = tmp.x + dx[i];
            if (y < 0 || x < 0 || y >= n || x >= m)
                continue;
            if (visited[y][x][tmp.z] == false && vec[y][x][tmp.z] == 0)
            {
                visited[y][x][tmp.z] = true;
                vec[y][x][tmp.z] = 1;
                target--;
                q.push(make_pos(y, x, tmp.z, tmp.t + 1));
            }
        }
        for (int i = 0; i < 2; i++)
        {
            int z = tmp.z + dz[i];
            if (z < 0 || z >= h)
                continue;
            if (visited[tmp.y][tmp.x][z] == false && vec[tmp.y][tmp.x][z] == 0)
            {
                visited[tmp.y][tmp.x][z] = true;
                vec[tmp.y][tmp.x][z] = 1;
                target--;
                q.push(make_pos(tmp.y, tmp.x, z, tmp.t + 1));
            }
        }
    }
    if (target == 0)
        cout << res;
    else
        cout << -1;
}
