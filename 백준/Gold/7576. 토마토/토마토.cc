#include <iostream>
#include <utility>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int width, height;
int res;

int find_will_ripe_tomato(queue<pair<int, int> > q)
{
    int y, x, new_y, new_x;
    queue<pair<int, int> > q2;
    int result = 0;
    int flag = 1;
    while (flag == 1)
    {
        flag = 0;
        while (!q.empty())
        {
            y = q.front().first;
            x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                new_y = y + dy[i];
                new_x = x + dx[i];
                if (new_y < 0 || new_x < 0 || new_y >= height || new_x >= width)
                    continue;
                if (arr[new_y][new_x] == 0)
                {
                    flag = 1;
                    arr[new_y][new_x] = 1;
                    q2.push(make_pair(new_y, new_x));
                }
            }
        }
        q = q2;
        q2 = queue<pair<int, int> >();
        if (flag == 1)
            result++;
    }
    return (result);
}

int is_ripe_tomato()
{
    queue<pair<int, int> > q;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            if (arr[i][j] == 1)
                q.push(make_pair(i, j));
    }
    return (find_will_ripe_tomato(q));
}

int main()
{
    fast;
    cin >> width >> height;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            cin >> arr[i][j];
    }
    res = is_ripe_tomato();
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            if (arr[i][j] == 0)
            {
                cout << -1;
                return (0);
            }
    }
    cout << res;
}
