#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    fast;
    int size, apple, move, res = 0, x, y;
    int time, move_dir = 2;
    int new_x, new_y;
    char dir;
    cin >> size >> apple;
    vector<vector<int> > vec(size, vector<int>(size, 0));
    vector<pair<int, int> > snake;
    snake.push_back(make_pair(0, 0));
    for (int i = 0; i < apple; i++)
    {
        cin >> y >> x;
        vec[y - 1][x - 1] = 1;
    }
    cin >> move;
    x = 1;
    y = 0;
    for (int i = 0; i < move; i++)
    {
        cin >> time >> dir;
        for (int j = res; j < time; j++)
        {
            res++;
            new_y = snake.back().first + y;
            new_x = snake.back().second + x;
            if (new_x < 0 || new_y < 0 || new_x >= size || new_y >= size)
            {
                cout << res;
                return 0;
            }
            if (vec[new_y][new_x] == 1)
            {
                snake.push_back(make_pair(new_y, new_x));
                vec[new_y][new_x] = 0;
            }
            else
            {
                if (find(snake.begin(), snake.end(), make_pair(new_y, new_x)) != snake.end())
                {
                    cout << res;
                    return 0;
                }
                snake.push_back(make_pair(new_y, new_x));
                snake.erase(snake.begin());
            }
        }
        if (dir == 'D')
        {
            move_dir++;
            move_dir %= 4;
        }
        else
        {
            move_dir--;
            if (move_dir < 0)
                move_dir = 3;
        }
        x = dx[move_dir];
        y = dy[move_dir];
    }
    while (1)
    {
        res++;
        new_y = snake.back().first + y;
        new_x = snake.back().second + x;
        if (new_x < 0 || new_y < 0 || new_x >= size || new_y >= size)
        {
            cout << res;
            return 0;
        }
        if (vec[new_y][new_x] == 1)
        {
            snake.push_back(make_pair(new_y, new_x));
            vec[new_y][new_x] = 0;
        }
        else
        {
            if (find(snake.begin(), snake.end(), make_pair(new_y, new_x)) != snake.end())
            {
                cout << res;
                return 0;
            }
            snake.push_back(make_pair(new_y, new_x));
            snake.erase(snake.begin());
        }
    }
}
