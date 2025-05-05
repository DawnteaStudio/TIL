#include <iostream>
#include <queue>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[101][101];
int melted[101][101];
bool visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int height, width;
int res, be_melted;

bool is_cheese()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            visited[i][j] = false;
            melted[i][j] = 0;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            if (arr[i][j] == 1)
                return (false);
    }
    return (true);
}

void melt_cheese(int _x, int _y)
{
    int x, y;
    int new_x, new_y;
    queue<pair<int, int> > q;

    q.push(make_pair(_y, _x));
    visited[0][0] = true;
    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            new_y = y + dy[i];
            new_x = x + dx[i];
            if (new_y < 0 || new_x < 0 || new_y >= height || new_x >= width || visited[new_y][new_x])
                continue;
            visited[new_y][new_x] = true;
            if (arr[new_y][new_x] == 1)
                melted[new_y][new_x] = melted[y][x] + 1;
            else
                q.push(make_pair(new_y, new_x));
        }
    }
}

int main()
{
    fast;
    cin >> height >> width;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cin >> arr[i][j];
    }
    while (!is_cheese())
    {
        res++;
        be_melted = 0;
        melt_cheese(0, 0);
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (melted[i][j] != 0)
                {
                    arr[i][j] = 0;
                    be_melted++;
                }
            }
        }
    }
    cout << res << '\n' << be_melted << '\n';
}
