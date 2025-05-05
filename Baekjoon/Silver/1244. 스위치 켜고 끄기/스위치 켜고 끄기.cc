#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void exec(int arr[], int sex, int num, int N)
{
    int left = num - 1, right = num + 1;

    if (sex == 1)
    {
        for (int i = num; i <= N; i += num)
        {
            if (arr[i] == 1)
                arr[i] = 0;
            else
                arr[i] = 1;
        }
    }
    else
    {
        if (arr[num] == 1)
            arr[num] = 0;
        else
            arr[num] = 1;
        while (left >= 1 && right <= N)
        {
            if (arr[left] == arr[right])
            {
                if (arr[left] == 0)
                {
                    arr[left] = 1;
                    arr[right] = 1;
                }
                else
                {
                    arr[left] = 0;
                    arr[right] = 0;
                }
            }
            else
                break;
            left--;
            right++;
        }
    }
}

int main()
{
    fast;

    int N, stu, sex, num;
    cin >> N;
    int arr[N + 1];
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    cin >> stu;
    for (int i = 0; i < stu; i++)
    {
        cin >> sex >> num;
        exec(arr, sex, num, N);
    }
    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
}