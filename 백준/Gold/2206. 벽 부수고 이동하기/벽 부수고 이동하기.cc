#include <iostream>
#include <string>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

typedef struct s_pos
{
    int y;
    int x;
    bool chance;
} pos;

int res[1001][1001][2];
int height, width;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(queue<pos>& q, int arr[][1001])
{
    pos p;
    int new_x, new_y;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            new_y = p.y + dy[i];
            new_x = p.x + dx[i];
            if (new_y < 0 || new_x < 0 || new_y >= height || new_x >= width)
                continue;
            if (arr[new_y][new_x] == 1)
            {
                if (p.chance == false)
                    continue;
                else
                {
                    if (res[new_y][new_x][1] > res[p.y][p.x][0] + 1 || res[new_y][new_x][1] == 0)
                    {
                        res[new_y][new_x][1] = res[p.y][p.x][0] + 1;
                        q.push({new_y, new_x, false});
                    }
                }
            }
            else
            {
                if (p.chance == true)
                {
                    if (res[new_y][new_x][0] > res[p.y][p.x][0] + 1 || res[new_y][new_x][0] == 0)
                    {
                        res[new_y][new_x][0] = res[p.y][p.x][0] + 1;
                        q.push({new_y, new_x, true});
                    }
                }
                else
                {
                    if (res[new_y][new_x][1] > res[p.y][p.x][1] + 1 || res[new_y][new_x][1] == 0)
                    {
                        res[new_y][new_x][1] = res[p.y][p.x][1] + 1;
                        q.push({new_y, new_x, false});
                    }
                }
            }
        }
    }
}

int main()
{
    fast;
    string input;
    cin >> height >> width;
    int arr[1001][1001];
    queue<pos> q;
    q.push({0, 0, true});
    res[0][0][0] = 1;
    for (int i = 0; i < height; i++)
    {
        cin >> input;
        for (int j = 0; j < width; j++)
            arr[i][j] = input[j] - '0';
    }
    bfs(q, arr);
    if (res[height - 1][width - 1][0] == 0 && res[height - 1][width - 1][1] == 0)
        cout << -1;
    else if (res[height - 1][width - 1][0] != 0 && res[height - 1][width - 1][1] != 0)
        cout << (res[height - 1][width - 1][0] < res[height - 1][width - 1][1] ? res[height - 1][width - 1][0] : res[height - 1][width - 1][1]);
    else if (res[height - 1][width - 1][0] == 0)
        cout << res[height - 1][width - 1][1];
    else
        cout << res[height - 1][width - 1][0];
}
