#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N, M, cnt;

int main()
{
    fast;
    cin >> N >> M;
    int num1, num2;

    if (N < 3)
    {
        cout << cnt;
        return 0;
    }
    int **arr = new int*[N+1];
    for (int i = 0; i <= N; i++)
        arr[i] = new int[N+1];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            arr[i][j] = 0;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> num1 >> num2;
        if (num1 > num2)
            arr[num2][num1] = 1;
        else
            arr[num1][num2] = 1;
    }
    for (int i = 1; i <= N - 2; i++)
    {
        for (int j = i + 1; j <= N - 1; j++)
        {
            if (arr[i][j] == 1)
                continue;
            for (int k = j + 1; k <= N; k++)
            {
                if (arr[i][k] == 1 || arr[j][k] == 1)
                    continue;
                cnt++;
            }
        }
    }
    cout << cnt;
    for (int i = 0; i <= N; i++)
        delete[] arr[i];
    delete[] arr;
}