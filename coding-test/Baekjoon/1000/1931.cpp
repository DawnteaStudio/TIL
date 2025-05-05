#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    int N, start, end, time, res;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;
        v[i].first = end;
        v[i].second = start;
    }
    sort(v.begin(), v.end());
    time = v[0].first;
    res = 1;
    for (int i = 1; i < N; i++)
    {
        if (v[i].second < time)
            continue;
        time = v[i].first;
        res++;
    }
    cout << res;
}