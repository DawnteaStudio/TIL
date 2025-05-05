#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, s, res = 0;

void    solve(int *arr, int value, int depth)
{
    if (depth == n)
    {
        if (value == s)
            res++;
        return;
    }
    solve(arr, value, depth + 1);
    solve(arr, value + arr[depth], depth + 1);
}

int main()
{
    fast;
    int tmp;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    solve(arr, arr[0], 1);
    solve(arr, 0, 1);
    if (s == 0)
        res--;
    cout << res;
}