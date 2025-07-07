#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
    cin >> n >> m;
    int arr[100001] = {0};
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        arr[a - 1]++;
        arr[b - 1]++;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
    return (0);
}