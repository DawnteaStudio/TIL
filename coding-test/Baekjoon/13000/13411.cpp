#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<double, int> &a, pair<double, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    fast;
    int n;
    cin >> n;

    int x, y, v;
    double res;
    vector<pair<double, int> > vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> v;
        res = sqrt(x * x + y * y) / (double)v;
        vec[i] = make_pair(res, i + 1);
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << vec[i].second << '\n';
}