#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, k, cnt = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cnt++;
        if (cnt == k)
        {
            cout << i;
            break;
        }
        if (i == n)
            cout << 0;
    }
}