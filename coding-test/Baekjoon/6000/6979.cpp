#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void    solve(vector<int> &x, vector<int> &y)
{
    int len = x.size();
    int res = 0;

    for (int i = 0; i < len; i++)
    {
        int tmp = 0;
        for (int j = i; j < len; j++)
        {
            if (y[j] >= x[i])
                tmp = j - i;
        }
        if (tmp > res)
            res = tmp;
    }
    cout << "The maximum distance is " << res << '\n' << '\n';
}

int main()
{
    fast;
    int n, c;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        vector<int> x(c);
        vector<int> y(c);
        for (int j = 0; j < c; j++)
            cin >> x[j];
        for (int j = 0; j < c; j++)
            cin >> y[j];
        solve(x, y);
    }
}
