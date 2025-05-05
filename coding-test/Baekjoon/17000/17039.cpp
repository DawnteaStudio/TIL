#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int arr[3];
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr, arr + 3);
    if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1)
        cout << 0 << "\n" << 0;
    else {
        int min_len = 2;
        if (arr[1] - arr[0] == 2 || arr[2] - arr[1] == 2)
            min_len = 1;
        int max_len = max(arr[1] - arr[0], arr[2] - arr[1]);
        cout << min_len  << "\n" << max_len - 1;
    }
}