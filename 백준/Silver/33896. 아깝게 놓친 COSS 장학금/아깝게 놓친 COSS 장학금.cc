#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct info {
    string name;
    int score;
    int risk;
    int cost;
    int prime;
};

bool cmp(info &a, info &b)
{
    if (a.prime != b.prime)
        return a.prime > b.prime;
    if (a.cost != b.cost)
        return a.cost < b.cost;
    return a.name < b.name;
}

int main()
{
    fast;
    int n;
    cin >> n;
    vector<info> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i].name >> vec[i].score >> vec[i].risk >> vec[i].cost;
        vec[i].prime = (vec[i].score * vec[i].score * vec[i].score) / ((vec[i].risk + 1) * vec[i].cost);
    }
    sort(vec.begin(), vec.end(), cmp);
    cout << vec[1].name;
}
