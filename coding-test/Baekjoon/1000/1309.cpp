#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;
    int arr[n][3];
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 1;
    for (int i = 1; i < n; i++)
    {
        arr[i][0] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % 9901;
        arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % 9901;
        arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % 9901;
    }
    cout << (arr[n - 1][0] + arr[n - 1][1] + arr[n - 1][2]) % 9901;
}