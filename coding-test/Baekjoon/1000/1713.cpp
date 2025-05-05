#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int N, M;
    bool duplicate, done;
    int tmp_idx, min;
    cin >> N >> M;

    int **arr = new int *[N];
    int *buff = new int[M];
    int *res = new int[N];
    int *times = new int[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[2];
        arr[i][0] = 0;
        arr[i][1] = 0;
        times[i] = 0;
        res[i] = 0;
    }
    for (int i = 0; i < M; i++)
        cin >> buff[i];
    for (int i = 0; i < M; i++)
    {
        duplicate = false;
        done = false;
        for (int j = 0; j < N; j++)
        {
             if (arr[j][0] == buff[i])
            {
                arr[j][1]++;
                duplicate = true;
                for (int k = 0; k < N; k++)
                {
                    if (arr[k][0] != 0)
                        times[k]++;
                }
                break;
            }
        }
        if (!duplicate)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[j][0] == 0)
                {
                    arr[j][0] = buff[i];
                    arr[j][1] = 1;
                    done = true;
                    for (int k = 0; k < N; k++)
                    {
                        if (arr[k][0] != 0)
                            times[k]++;
                    }
                    break;
                }
            }
        }
        if (!duplicate && !done)
        {
            min = 1000;
            tmp_idx = 0;
            for (int j = 0; j < N; j++)
            {
                if (arr[j][1] < min)
                {
                    min = arr[j][1];
                    tmp_idx = j;
                }
                else if (arr[j][1] == min)
                {
                    if (times[tmp_idx] < times[j])
                        tmp_idx = j;
                }
            }
            arr[tmp_idx][0] = buff[i];
            arr[tmp_idx][1] = 1;
            for (int k = 0; k < N; k++)
            {
                if (arr[k][0] != 0)
                    times[k]++;
            }
            times[tmp_idx] = 1;
        }
    }

    for (int i = 0; i < N; i++)
        res[i] = arr[i][0];
    sort(res, res + N);
    for (int i = 0; i < N; i++)
    {
        if (res[i] != 0)
            cout << res[i] << ' ';
    }
    cout << '\n';
    delete[] buff;
    delete[] times;
    delete[] res;
    for (int i = 0; i < N; i++)
        delete[] arr[i];
    delete[] arr;
}