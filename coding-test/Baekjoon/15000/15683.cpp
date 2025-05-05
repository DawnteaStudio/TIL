#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m, cnt, res;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void draw_vec(int y, int x, int dir, vector<vector<int> > &vec)
{
    dir %= 4;
    while (y >= 0 && x >= 0 && y < n && x < m)
    {
        if (vec[y][x] == 0)
            vec[y][x] = -1;
        else if (vec[y][x] == 6)
            break;
        y += dy[dir];
        x += dx[dir];
    }
}

void    solve(vector<vector<int> > vec, vector<pair<int, int> > &cctv, int depth)
{
    if (depth == cnt)
    {
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (vec[i][j] == 0)
                    tmp++;
        }
        if (res > tmp)
            res = tmp;
        return;
    }
    vector<vector<int> > tmp;
    switch (vec[cctv[depth].first][cctv[depth].second])
    {
        case 1:
            for (int i = 0; i < 4; i++)
            {
                tmp = vec;
                draw_vec(cctv[depth].first, cctv[depth].second, i, tmp);
                solve(tmp, cctv, depth + 1);
            }
            break;
        case 2:
            for (int i = 0; i < 2; i++)
            {
                tmp = vec;
                draw_vec(cctv[depth].first, cctv[depth].second, i, tmp);
                draw_vec(cctv[depth].first, cctv[depth].second, i + 2, tmp);
                solve(tmp, cctv, depth + 1);
            }
            break;
        case 3:
            for (int i = 0; i < 4; i++)
            {
                tmp = vec;
                draw_vec(cctv[depth].first, cctv[depth].second, i, tmp);
                draw_vec(cctv[depth].first, cctv[depth].second, i + 1, tmp);
                solve(tmp, cctv, depth + 1);
            }
            break;
        case 4:
            for (int i = 0; i < 4; i++)
            {
                tmp = vec;
                draw_vec(cctv[depth].first, cctv[depth].second, i, tmp);
                draw_vec(cctv[depth].first, cctv[depth].second, i + 1, tmp);
                draw_vec(cctv[depth].first, cctv[depth].second, i + 2, tmp);
                solve(tmp, cctv, depth + 1);
            }
            break;
        case 5:
            tmp = vec;
            for (int i = 0; i < 4; i++)
                draw_vec(cctv[depth].first, cctv[depth].second, i, tmp);
            solve(tmp, cctv, depth + 1);
            break;
        default:
            break;
    }
}

int main() {
    fast;
    cin >> n >> m;

    vector<vector<int> > vec(n, vector<int>(m));
    vector<pair<int, int> > cctv;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
            if (vec[i][j] != 0 && vec[i][j] != 6)
                cctv.push_back(make_pair(i, j));
            if (vec[i][j] == 0)
                res++;
        }
    }
    cnt = cctv.size();
    if (cnt == 0)
        cout << res;
    else
    {
        solve(vec, cctv, 0);
        cout << res;
    }
}