#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct cmp {
    bool operator()(const int &a, const int &b) {
        return a > b;
    }
};

int main()
{
    fast;
    int n;
    cin >> n;

    vector<pair<int, int> > vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end());

    priority_queue<int, vector<int>, cmp> q;
    q.push(vec[0].second);

    for (int i = 1; i < n; i++) {
        if (q.top() <= vec[i].first)
            q.pop();
        q.push(vec[i].second);
    }
    cout << q.size();
}
