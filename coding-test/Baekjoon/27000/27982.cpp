#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct cube {
    int x;
    int y;
    int z;
};

bool solve(vector<vector<vector<bool> > > &space, cube &c, int n)
{
    int diff;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
                diff = 1;
            else
                diff = -1;
            switch (i)
            {
                case 0:
                    if (c.x + diff <= 0 || c.x + diff > n || space[c.x + diff][c.y][c.z] == false)
                        return false;
                    break;
                case 1:
                    if (c.y + diff <= 0 || c.y + diff > n || space[c.x][c.y + diff][c.z] == false)
                        return false;
                    break;
                case 2:
                    if (c.z + diff <= 0 || c.z + diff > n || space[c.x][c.y][c.z + diff] == false)
                        return false;
                    break;
                default:
                    break;
            }
        }
    }
    return true;
}

int main() {
    fast;
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<cube> vec(m);
    cube c;
    vector<vector<vector<bool> > > space(n + 1, vector<vector<bool> >(n + 1, vector<bool> (n + 1, false)));

    if (m < 7)
        cout << 0;
    else
    {
        for (int i = 0; i < m; i++)
        {
            cin >> c.x >> c.y >> c.z;
            vec[i] = c;
            space[c.x][c.y][c.z] = true;
        }
        for (int i = 0; i < m; i++)
        {
            if (solve(space, vec[i], n))
                cnt++;
        }
        cout << cnt;
    }
}
