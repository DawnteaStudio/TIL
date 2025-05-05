#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n;
int cnt;

bool    is_valid(int y, int x, int arr[15][15])
{
    int tmp = 1;

    for (int i = x - 1; i >= 0; i--)
    {
        if (arr[y][i] == 1)
            return (false);
        if (y - tmp >= 0 && arr[y - tmp][i] == 1)
            return (false);
        if (y + tmp < n && arr[y + tmp][i] == 1)
            return (false);
        tmp++;
    }
    return (true);
}

void    find_case(int line, int arr[15][15])
{
    if (line == n)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (is_valid(i, line, arr))
        {
            arr[i][line] = 1;
            find_case(line + 1, arr);
            arr[i][line] = 0;
        }
    }
}

int main()
{
    cin >> n;
    int arr[15][15];

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            arr[i][j] = 0;
    
    find_case(0, arr);
    cout << cnt;
}
