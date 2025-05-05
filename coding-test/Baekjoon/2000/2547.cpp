#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    long long candy, tmp, n;
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        candy = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            candy += tmp;
            if (candy > n)
                candy -= (candy / n) * n;
        }
        if (candy % n == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
