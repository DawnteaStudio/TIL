#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    fast;
    int n, value;
    cin >> n;

    string t, name;
    vector<pair<string, int> > stu;
    map<string, int> is_exist;
    for (int i = 0; i < n; i++) {
        cin >> t >> name;
        value = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
        if (is_exist.find(name) == is_exist.end())
            is_exist[name] = value;
        else
            is_exist[name] += value;
    }
    for (map<string, int>::iterator iter = is_exist.begin(); iter != is_exist.end(); iter++)
        stu.push_back(make_pair(iter->first, iter->second));
    sort(stu.begin(), stu.end(), cmp);
    int cnt = stu.size();
    for (int i = 0; i < cnt; i++) {
        cout << stu[i].first << " ";
        if (stu[i].second <= 100)
            cout << 10;
        else {
            int tmp = 10;
            tmp += ((stu[i].second - 100) / 50) * 3;
            if ((stu[i].second - 100) % 50 != 0)
                tmp += 3;
            cout << tmp;
        }
        cout << '\n';
    }
}