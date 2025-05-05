#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool    solve(string &layer, string &tmp, int start, int m)
{
    for (int i = 0; i < m - start; i++)
    {
        if (layer[start + i] != tmp[i] && layer[i] != tmp[start + i])
            return false;
    }
    return true;
}

int main()
{
    fast;
    int n, m;
    bool flag = true;
    cin >> n >> m;

    string layer, tmp;
    cin >> layer;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            if (solve(layer, tmp, j, m) == true)
            {
                layer = tmp;
                flag = true;
                break;
            }
            else
                flag = false;
        }
        if (!flag)
            break;
    }

    if (flag)
        cout << 1;
    else
        cout << 0;
}
