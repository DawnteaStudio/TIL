#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool comp(pair<int, char> &a, pair<int, char> &b)
{
    return a.first < b.first;
}

int main()
{
    fast;
    int n, m, t = 0;
    cin >> n >> m;

    int a, b;
    char c;
    vector<vector<pair<int, char>>> v(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (t < c)
            t = c;
        v[a].push_back(make_pair(b, c));
    }
    map<int, string> input;

    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end(), comp);
        int len = v[i].size();
        for (int j = 0; j < len; j++)
        {
            input[v[i][j].first] += v[i][j].second;
        }
    }
    for (int i = 0; i <= t; i++)
    {
        if (input.find(i) != input.end())
            cout << input[i];
    }
}