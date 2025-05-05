#include <iostream>
#include <string>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int res = -1;

struct node
{
    int x;
    int y;
    int crushed;
};

int main() {
    fast;
    int n, m;
    string input;
    cin >> n >> m;

    int arr[n][m];
    int res[n][m][2];
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = input[j] - '0';
            res[i][j][0] = 0;
            res[i][j][1] = 0;
        }
    }
    queue<node> q;
    node t = {0, 0, 0};
    res[0][0][0] = 1;
    q.push(t);
    while (!q.empty())
    {
        int new_x, new_y;
        node tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            new_x = tmp.x + dx[i];
            new_y = tmp.y + dy[i];
            if (new_x < 0 || new_y < 0 || new_x >= m || new_y >= n)
                continue;
            if (tmp.crushed)
            {
                if (arr[new_y][new_x] == 0)
                {
                    if (res[new_y][new_x][1] > res[tmp.y][tmp.x][1] + 1 || res[new_y][new_x][1] == 0)
                    {
                        node Node = {new_x, new_y, 1};
                        res[new_y][new_x][1] = res[tmp.y][tmp.x][1] + 1;
                        q.push(Node);
                    }
                }
            }
            else
            {
                if (arr[new_y][new_x] == 1)
                {
                    if (res[new_y][new_x][1] > res[tmp.y][tmp.x][0] + 1 || res[new_y][new_x][1] == 0)
                    {
                        node Node = {new_x, new_y, 1};
                        res[new_y][new_x][1] = res[tmp.y][tmp.x][0] + 1;
                        q.push(Node);
                    }
                }
                else
                {
                    if (res[new_y][new_x][0] > res[tmp.y][tmp.x][0] + 1 || res[new_y][new_x][0] == 0)
                    {
                        node Node = {new_x, new_y, 0};
                        res[new_y][new_x][0] = res[tmp.y][tmp.x][0] + 1;
                        q.push(Node);
                    }
                }
            }
        }
    }

    if (res[n - 1][m - 1][0] != 0 && res[n - 1][m - 1][1] != 0)
        cout << (res[n - 1][m - 1][0] > res[n - 1][m - 1][1] ? res[n - 1][m - 1][1] : res[n - 1][m - 1][0]);
    else if (res[n - 1][m - 1][0] != 0)
        cout << res[n - 1][m - 1][0];
    else if (res[n - 1][m - 1][1] != 0)
        cout << res[n - 1][m - 1][1];
    else
        cout << -1 << '\n';
}
