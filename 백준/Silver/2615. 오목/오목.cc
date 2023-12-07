#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int go_stage[19][19];

bool check_dir(int dir_y, int dir_x, int stone, int y, int x)
{
    int cnt = 1;
    if (y-dir_y >= 0 && y-dir_y < 19 && x-dir_x >= 0 && x-dir_x < 19)
    {
        if(go_stage[y-dir_y][x-dir_x] == stone)
            return false;
    }
    while (1)
    {
        y += dir_y;
        x += dir_x;
        if (y < 0 || x < 0 || y >= 19 || x >= 19)
            break;;
        if (go_stage[y][x] != stone)
            break;
        else
            cnt++;
    }
    if (cnt == 5)
        return true;
    return false;
}

bool go_dfs(int y, int x, int stone)
{
    int dx[4] = {1, 1, 1, 0};
    int dy[4] = {-1, 0, 1, 1};

    for (int i = 0; i < 4; i++)
    {
        if (y + dy[i] < 0 || y + dy[i] >= 19 || x + dx[i] < 0 || x + dx[i] >= 19)
            continue;
        if (go_stage[y + dy[i]][x + dx[i]] != stone)
            continue;
        else
        {
            if (check_dir(dy[i], dx[i], stone, y, x))
                return true;
        }
    }
    return false;
}

int main()
{
    fast;

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
            cin >> go_stage[i][j];
    }

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (go_stage[i][j] == 0)
                continue;
            if (go_dfs(i, j, go_stage[i][j]))
            {
                cout << go_stage[i][j] << '\n' << i+1 << " " << j+1;
                return 0;
            }
        }
    }
    cout << 0;
}