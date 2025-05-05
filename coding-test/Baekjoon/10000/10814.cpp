#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool    cmp(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b)
{
    if (a.first > b.first)
        return false;
    else if (a.first == b.first)
    {
        if (a.second.second > b.second.second)
            return false;
    }
    return true;
}

int main()
{
    fast;
    int n, tmp;
    string str;
    cin >> n;
    vector<pair<int, pair<string , int>>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp >> str;
        v.push_back({tmp, {str, i}});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << v[i].first << ' ' << v[i].second.first << '\n';
}
