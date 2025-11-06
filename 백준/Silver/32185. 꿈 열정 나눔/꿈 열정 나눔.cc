#include <iostream>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct cmp {

    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    }
};

int main()
{
    fast;
    int n, m, v, p, s, jae;
    cin >> n >> m;

    cin >> v >> p >> s;
    jae = v + p + s;
    priority_queue<pair<int, int>, vector<pair<int,int> >, cmp> q;
    for (int i = 1; i <= n; i++) {
        cin >> v >> p >> s;
        if (jae < v + p + s)
            continue;
        q.push({v + p + s, i});
    }
    cout << 0 << " ";
    for (int i = 1; i < m; i++) {
        if (q.empty())
            break;
        cout << q.top().second << " ";
        q.pop();
    }
}
