#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

pair<int, int>  get_dir(char c)
{
    if (c == 'W')
        return (make_pair(-1, 0));
    else if (c == 'D')
        return (make_pair(0, 1));
    else if (c == 'A')
        return (make_pair(0, -1));
    else
        return (make_pair(1, 0));
}

int main() {
    fast;
    int h, w, n;
    pair<int, int> dao;
    string res = "";
    cin >> h >> w;

    vector<vector<char> > vec(h + 1, vector<char>(w + 1));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> vec[i][j];
            if (vec[i][j] == 'D')
                dao = make_pair(i, j);
        }
    }

    cin >> n;
    char cmd1, cmd2;
    vector<pair<char, char> > cmd(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> cmd1 >> cmd2;
        cmd[i] = make_pair(cmd1, cmd2);
    }

    queue<pair<pair<int, string>, pair<int, int> > > q;
    q.push(make_pair(make_pair(0, ""), dao));
    while (!q.empty())
    {
        int depth = q.front().first.first + 1;
        string cmds = q.front().first.second;
        int now_y = q.front().second.first;
        int now_x = q.front().second.second;
        q.pop();

        for (int i = 0; i < 2; i++)
        {
            if (depth > n)
                break;
            pair<int, int> dir;
            char mv;
            if (i == 0)
                mv = cmd[depth].first;
            else
                mv = cmd[depth].second;
            dir = get_dir(mv);
            int y = now_y + dir.first;
            int x = now_x + dir.second;
            if (y < 1 || x < 1 || y > h || x > w || vec[y][x] == '@')
                continue;
            string tmp = cmds;
            tmp += mv;
            if (vec[y][x] == 'Z')
            {
                res = tmp;
                break;
            }
            q.push(make_pair(make_pair(depth, tmp), make_pair(y, x)));
        }
        if (!res.empty())
        {
            cout << "YES\n" << res;
            break;
        }
    }
    if (res.empty())
        cout << "NO\n";
}