#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, res, input;
    cin >> n;

    int candy, k;
    for (int i = 0; i < n; i++)
    {
        res = 0;
        cin >> candy >> k;
        for (int j = 0; j < candy; j++)
        {
            cin >> input;
            res += input / k;
        }
        cout << res << '\n';
    }
}
