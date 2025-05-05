#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    fast;
    int n;
    cin >> n;

    string t, name;
    map<string, int> totalTime;
    for (int i = 0; i < n; i++) {
        cin >> t >> name;
        int value = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
        if (totalTime.find(name) == totalTime.end())
            totalTime[name] = value;
        else
            totalTime[name] += value;    }

    vector<pair<string, int>> stu;
    for (auto &iter : totalTime) {
        stu.push_back({iter.first, iter.second});
    }
    for (auto &s : stu) {
        int exceedTime = max(s.second - 100, 0);
        int totalPay = 10 + 3 * (exceedTime / 50);
        if (exceedTime % 50)
            totalPay += 3;
        s.second = totalPay;
    }
    sort(stu.begin(), stu.end(), cmp);

    for (auto &s : stu)
        cout << s.first << " " << s.second << '\n';
}
