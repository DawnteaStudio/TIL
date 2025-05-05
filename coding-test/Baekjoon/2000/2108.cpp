#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

int main()
{
    fast;
    int n, total = 0;
    cin >> n;
    vector<int> vec(n);
    map<int, int> mode;

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        total += vec[i];
        if (mode.find(vec[i]) == mode.end())
            mode[vec[i]] = 1;
        else
            mode[vec[i]]++;
    }
    sort(vec.begin(), vec.end());

    cout.precision(1);
    cout << fixed;
    double avg = static_cast<double>(total) / n;

    cout << static_cast<int>(round(avg)) << '\n' << vec[n / 2] << '\n';

    vector<pair<int, int> > mode_vec;
    for (map<int, int>::iterator iter = mode.begin(); iter != mode.end(); iter++)
        mode_vec.push_back(make_pair((*iter).first, (*iter).second));
    sort(mode_vec.begin(), mode_vec.end(), cmp);
    int mode_res;
    if (mode_vec.size() > 1 && mode_vec[0].second == mode_vec[1].second)
        mode_res = mode_vec[1].first;
    else
        mode_res = mode_vec[0].first;
    cout << mode_res << '\n' << vec[n - 1] - vec[0];
}