#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void)
{
    fast;
    int n, tmp;
    cin >> n;
    int arr[10001] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr[tmp]++;
    }
    for (int i =1; i <= 10000; i++)
    {
        for (int j = 0; j < arr[i]; j++)
            cout << i << '\n';
    }
}