#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, tmp;
    double res;
    cin >> n;

    double arr[5] = {350.34, 230.90, 190.55, 125.30, 180.90};
    cout.precision(2);
    cout << fixed;
    for (int i = 0; i < n; i++)
    {
        res = 0;
        for (int j = 0; j < 5; j++)
        {
            cin >> tmp;
            res += tmp * arr[j];
        }
        cout << "$" << res << '\n';
    }
}