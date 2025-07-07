#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, sum = 0, min_n = 100;
    for (int i = 0; i < 7; i++)
    {
        cin >> n;
        if (n % 2 == 1)
        {
            sum += n;
            min_n = min(n, min_n);
        }
    }
    if (sum == 0)
        cout << -1;
    else
        cout << sum << '\n'
             << min_n;
}