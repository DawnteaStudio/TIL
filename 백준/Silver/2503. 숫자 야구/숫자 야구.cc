#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;

bool check(int test, int num, int strike, int ball)
{
    int tmp_str = 0;
    int tmp_ball = 0;
    int arr_test[3];
    int arr_num[3];

    arr_test[0] = test/100;
    arr_test[1] = (test/10)%10;
    arr_test[2] = test%10;

    arr_num[0] = num/100;
    arr_num[1] = (num/10)%10;
    arr_num[2] = num%10;

    for (int i = 0; i < 3; i++)
    {
        if (arr_test[i] == 0)
            return false;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            if (i == j)
                continue;
            if (arr_test[i] == arr_test[j])
                return false;
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr_test[i] == arr_num[j])
            {
                if (i == j)
                    tmp_str++;
                else
                    tmp_ball++;
            }
        }
    }
    if (tmp_str == strike && tmp_ball == ball)
        return true;
    return false;
}

int main()
{
    fast;
    cin >> N;
    int *num = new int[N];
    int *strike = new int[N];
    int *ball = new int[N];
    int j, cnt = 0;

    for (int i = 0; i < N; i++)
        cin >> num[i] >> strike[i] >> ball[i];
    for (int i = 123; i <= 999; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (!check(i, num[j], strike[j], ball[j]))
                break;
        }
        if (j == N)
            cnt++;
    }
    cout << cnt;
}