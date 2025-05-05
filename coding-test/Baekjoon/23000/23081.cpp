#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int n, y = -1, x = -1, res = 0;

int get_sum(int i, int j, int dir, vector<string> &board)
{
    int res = 0, tmp = 0;

    i += dy[dir];
    j += dx[dir];
    while (i >= 0 && j >= 0 && i < n && j < n)
    {
        if (board[i][j] == 'B')
            return res;
        else if (board[i][j] == 'W')
            res++;
        else
            return 0;
        i += dy[dir];
        j += dx[dir];
    }
    return 0;
}

void    get_res(int i, int j, vector<string> &board)
{
    int sum[8] = {0};
    int sums = 0;

    for (int k = 0; k < 8; k++)
        sum[k] = get_sum(i, j, k, board);
    for (int k = 0; k < 8; k++)
            sums += sum[k];
    if (res <= sums && sums != 0)
    {
        if (res == sums)
        {
            if (y > i)
            {
                y = i;
                x = j;
            }
            else if (y == i)
            {
                if (x > j)
                    x = j;
            }
        }
        else
        {
            y = i;
            x = j;
            res = sums;
        }
    }
}

int main() {
    fast;
    cin >> n;

    vector<string> board(n);
    for (int i = 0; i < n; i++)
        cin >> board[i];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
                get_res(i, j, board);
        }
    }
    if (y == -1)
        cout << "PASS";
    else
        cout << x << " " << y << '\n' << res;
}
