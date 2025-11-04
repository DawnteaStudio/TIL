#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int get_sec(string &str)
{
    int len = str.length();

    int res = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            res += str[i] - '0';
    }
    return res;
}

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.first.length() != b.first.length())
        return a.first.length() < b.first.length();
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    fast;
    int n;
    cin >> n;

    string str;

    vector<pair<string, int> > vec(n);
    for (int i = 0; i < n; i++) {
        cin >> str;
        vec[i].first = str;
        vec[i].second = get_sec(str);
    }
    sort (vec.begin(), vec.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << vec[i].first << '\n';
}
