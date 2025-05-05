#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j > 0; j--)
            cout << ' ';
        for (int k = 0; k < 2 * i - 1; k++)
            cout << '*';
        cout << '\n';
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i; j < n; j++)
            cout << ' ';
        for (int k = 0; k < 2 * i - 1; k++)
            cout << '*';
        cout << '\n';
    }
}