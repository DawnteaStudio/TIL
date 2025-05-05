#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, time;
    cin >> n;

    int arr[n];
    int res[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    res[0] = arr[0];
    time = res[0];
    for (int i = 1; i < n; i++)
    {
        res[i] = res[i - 1] + arr[i];
        time += res[i];
    }
    cout << time;
}