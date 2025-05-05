#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;

    int n, m, tmp, s, e;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (i == 0)
            v[i] = tmp;
        else
            v[i] = tmp + v[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        if (s == 1)
            cout << v[e - 1] << '\n';
        else
            cout << v[e - 1] - v[s - 2] << '\n';
    }
}
