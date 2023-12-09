#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;
int score;
int base[4];
int player[50][10];
bool include[10];

void base_clear()
{
    for (int i = 1; i < 4; i++)
        base[i] = 0;
}

void cal_score(int tmp[10])
{
    int out = 0;
    int bat = 1;
    int inning = 0;
    int tmp_score = 0;
    base_clear();

    while (inning < N)
    {
        if (bat > 9)
            bat = 1;
        if (player[inning][tmp[bat]] == 0)
        {
            out++;
            bat++;
        }
        else if (player[inning][tmp[bat]] == 1)
        {
            if (base[3] == 1)
            {
                tmp_score++;
                base[3] = 0;
            }
            if (base[2] == 1)
            {
                base[3] = 1;
                base[2] = 0;
            }
            if (base[1] == 1)
                base[2] = 1;
            base[1] = 1;
            bat++;
        }
        else if (player[inning][tmp[bat]] == 2)
        {
            if (base[3] == 1)
            {
                tmp_score++;
                base[3] = 0;
            }
            if (base[2] == 1)
            {
                tmp_score++;
                base[2] = 0;
            }
            if (base[1] == 1)
            {
                base[3] = 1;
                base[1] = 0;
            }
            base[2] = 1;
            bat++;
        }
        else if (player[inning][tmp[bat]] == 3)
        {
            if (base[3] == 1)
            {
                tmp_score++;
                base[3] = 0;
            }
            if (base[2] == 1)
            {
                tmp_score++;
                base[2] = 0;
            }
            if (base[1] == 1)
            {
                tmp_score++;
                base[1] = 0;
            }
            base[3] = 1;
            bat++;
        }
        else
        {
            tmp_score++;
            for (int i = 1; i < 4; i++)
            {
                if (base[i] == 1)
                    tmp_score++;
            }
            base_clear();
            bat++;
        }

        if (out == 3)
        {
            base_clear();
            inning++;
            out = 0;
        }
    }
    if (tmp_score > score)
        score = tmp_score;
}

void make_tmp_order(int tmp[10], int arr[10])
{
    for (int i = 1; i < 10; i++)
        tmp[i] = arr[i];
}

void make_order(int arr[10], int cnt)
{
    if (cnt == 10)
    {
        cal_score(arr);
        return;
    }
    if (cnt == 4)
        make_order(arr, cnt + 1);
    else
    {
        int tmp[10];
        make_tmp_order(tmp, arr);

        for (int i = 1; i < 10; i++)
        {
            if (include[i] == true)
                continue;
            else
            {
                tmp[cnt] = i;
                include[i] = true;
                make_order(tmp, cnt + 1);
                include[i] = false;
            }
        }
    }
}

int main()
{
    int arr[10] = {0};
    fast;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < 10; j++)
            cin >> player[i][j];
    }
    arr[4] = 1;
    include[1] = true;
    make_order(arr, 1);
    cout << score;
}