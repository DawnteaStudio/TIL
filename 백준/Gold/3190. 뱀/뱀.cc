#include <iostream>
#include <utility>
#include <queue>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int map[101][101];

int main()
{
    fast;
    int N, K, L, y, x, dur;
    char d;
    cin >> N >> K;
    int times = 1, dir = 0;
    queue<pair<int, int> > snake;
    queue<pair<int, char> > directions;

    for (int i = 0; i < K; i++)
    {
        cin >> y >> x;
        map[y][x] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> dur >> d;
        directions.push(make_pair(dur, d));
    }

    snake.push(make_pair(1, 1));
    map[1][1] = 2;
    while (1)
    {
        y = snake.back().first + dy[dir];
        x = snake.back().second + dx[dir];

        if (x > N || y > N || x < 1 || y < 1)
            break;
        else if (map[y][x] == 2)
            break;
        else if (map[y][x] == 1)
        {
            snake.push(make_pair(y, x));
            map[y][x] = 2;
        }
        else
        {
            snake.push(make_pair(y, x));
            map[y][x] = 2;
            map[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }

        if (times == directions.front().first)
        {
            if (directions.front().second == 'D')
                dir = (dir + 1) % 4;
            else
            {
                dir = (dir - 1);
                if (dir == -1)
                    dir = 3;
            }
            directions.pop();
        }
        times++;
    }
    cout << times;
}