#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res, input_size;
char arr[50][50];
char tmp[50][50];

int find_same_candy(int y, int x, char tmp_c)
{
    int cnt_height = 1;
    int cnt_width = 1;
    for (int i = y + 1; i < input_size; i++)
    {
        if (tmp[i][x] == tmp_c)
            cnt_height++;
        else
            break;
    }
    for (int i = y - 1; i >= 0; i--)
    {
        if (tmp[i][x] == tmp_c)
            cnt_height++;
        else
            break;
    }
    for (int i = x + 1; i < input_size; i++)
    {
        if (tmp[y][i] == tmp_c)
            cnt_width++;
        else
            break;
    }
    for (int i = x - 1; i >= 0; i--)
    {
        if (tmp[y][i] == tmp_c)
            cnt_width++;
        else
            break;
    }
    if (cnt_height > cnt_width)
        return (cnt_height);
    else
        return (cnt_width);
}

void find_max_candy()
{
    int tmp_n = 0;
    char tmp_c;

    for (int i = 0; i < input_size; i++)
        for (int j = 0; j < input_size; j++)
        {
            tmp_c = tmp[i][j];
            tmp_n = find_same_candy(i, j, tmp_c);
            if (tmp_n > res)
                res = tmp_n;
        }
}

void cpy_arr()
{
    for (int i = 0; i < input_size; i++)
        for (int j = 0; j < input_size; j++)
            tmp[i][j] = arr[i][j];
}

void get_candy(int y, int x)
{
    cpy_arr();
    if (y != input_size - 1 && x != input_size - 1)
    {
        tmp[y][x] = arr[y][x + 1];
        tmp[y][x + 1] = arr[y][x];
        find_max_candy();
        cpy_arr();
        tmp[y][x] = arr[y + 1][x];
        tmp[y + 1][x] = arr[y][x];
        find_max_candy();
    }
    else if (y != input_size - 1 || x != input_size - 1)
    {
        if (y == input_size - 1)
        {
            tmp[y][x] = arr[y][x + 1];
            tmp[y][x + 1] = arr[y][x];
            find_max_candy();
        }
        else
        {
            tmp[y][x] = arr[y + 1][x];
            tmp[y + 1][x] = arr[y][x];
            find_max_candy();
        }
    }
}

int main()
{
    fast;
    string input;
    cin >> input_size;
    for (int i = 0; i < input_size; i++)
    {
        cin >> input;
        for (int j = 0; j < input_size; j++)
            arr[i][j] = input[j];
    }

    for (int y = 0; y < input_size; y++)
        for (int x = 0; x < input_size; x++)
            get_candy(y, x);
    cout << res;
}
