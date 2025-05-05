#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> n;
    int index;
    for (int i = 0; i < n; i++)
    {
        cin >> index;
        res += arr[index - 1];
    }
    cout << res;
}