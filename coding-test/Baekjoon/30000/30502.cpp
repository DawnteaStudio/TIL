#include <iostream>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
    cin >> n >> m;

    int a, c;
    char b;
    map<int, pair<int, int>> info;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (info.find(a) == info.end())
            info[a] = make_pair(-1, -1);
        if (b == 'P')
            info[a].first = c;
        else
            info[a].second = c;
    }
    int min_value = 0, max_value = n;
    for (auto iter = info.begin(); iter != info.end(); iter++)
    {
        if (iter->second.first == 0 || iter->second.second == 1)
            max_value--;
        if (iter->second.first == 1 && iter->second.second == 0)
            min_value++;
    }
    cout << min_value << " " << max_value;
    return (0);
}