#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long x, y;
int N;

long long ft_pow(int num)
{
    long long res = 1;
    for (int i = 0; i < num; i ++)
        res *= 2;
    return res;
}

void ft_find(string target)
{
    int *arr = new int[N];
    long long start_y = 1, start_x = 1, end_y = ft_pow(N), end_x = ft_pow(N);

    for (int i = 0; i < N; i++)
        arr[i] = target[i] - '0';

    for (int i = 0; i < N; i++)
    {
        switch (arr[i])
        {
        case 1:
            start_x = (start_x + end_x) / 2 + 1;
            end_y = (start_y + end_y) / 2;
            break;
        case 2:
            end_x = (start_x + end_x) / 2;
            end_y = (start_y + end_y) / 2;
            break;
        case 3:
            start_y = (start_y + end_y) / 2 + 1;
            end_x = (start_x + end_x) / 2;
            break;
        case 4:
            start_x = (start_x + end_x) / 2 + 1;
            start_y = (start_y + end_y) / 2 + 1;
            break;
        default:
            break;
        }
    }
    x = start_x;
    y = start_y;
    delete[] arr;
}

void ft_solve()
{
    int *arr = new int[N];
    long long min_y = 1, min_x = 1, max_y = ft_pow(N), max_x = ft_pow(N);

    for (int i = 0; i < N; i++)
    {
        if (x <= (min_x + max_x)/2)
        {
            if (y <= (min_y + max_y)/2)
            {
                arr[i] = 2;
                max_x = (min_x + max_x) / 2;
                max_y = (min_y + max_y) / 2;
            }
            else
            {
                arr[i] = 3;
                max_x = (min_x + max_x) / 2;
                min_y = (min_y + max_y) / 2 + 1;
            }
        }
        else
        {
            if (y <= (min_y + max_y)/2)
            {
                arr[i] = 1;
                min_x = (min_x + max_x) / 2 + 1;
                max_y = (min_y + max_y) / 2; 
            }
            else
            {
                arr[i] = 4;
                min_x = (min_x + max_x) / 2 + 1;
                min_y = (min_y + max_y) / 2 + 1; 
            }
        }
    }
    for (int i = 0; i < N; i++)
        cout<<arr[i];
    delete[] arr;
}

int main()
{
    long long dx, dy;
    string target;
    fast;
    cin >> N >> target >> dx >> dy;

    ft_find(target);
    x += dx;
    y -= dy;
    if (x < 1 || y < 1 || x > ft_pow(N) || y > ft_pow(N))
    {
        cout << -1;
        return 0;
    }
    ft_solve();
}