#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void    find_max(int col)
{
    vector<vector<int>> v(2, vector<int> (col));
    vector<vector<int>> res(2, vector<int> (col));
    int input, main_line;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> input;
            if (i == 0)
            {
                if (j % 2 == 0)
                    v[0][j] = input;
                else
                    v[1][j] = input;
            }
            else
            {
                if (j % 2 != 0)
                    v[0][j] = input;
                else
                    v[1][j] = input;
            }

        }
    }

    res[0][0] = v[0][0];
    res[1][0] = v[1][0];
    for (int i = 1; i < col; i++)
    {
        if (i < 2)
        {
            res[0][1] = v[0][1] + res[0][0];
            res[1][1] = v[1][1] + res[1][0];
        }
        else
        {
            res[0][i] = res[0][i - 1] > res[1][i - 2] ? res[0][i - 1] : res[1][i - 2];
            res[0][i] += v[0][i];
            res[1][i] = res[1][i - 1] > res[0][i - 2] ? res[1][i - 1] : res[0][i - 2];
            res[1][i] += v[1][i];
        }
    }
    cout << (res[0][col - 1] > res[1][col - 1] ? res[0][col - 1] : res[1][col - 1]) << '\n';
}

int main()
{
    fast;

    int T, col;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> col;
        find_max(col);
    }
}
