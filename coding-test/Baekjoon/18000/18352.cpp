#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    int n, m, k, x, res = 0;
    cin >> n >> m >> k >> x;
    vector<vector<int> > vec(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> d(n + 1, -1);
    queue<int> q;
    d[x] = 0;
    q.push(x);

    int from, to;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        vec[from].push_back(to);
    }

    while (!q.empty())
    {
        int target = q.front();
        visited[target] = true;
        q.pop();
        int size = vec[target].size();
        for (int i = 0; i < size; i++)
        {
            if (d[vec[target][i]] == -1)
                d[vec[target][i]] = d[target] + 1;
            else if (d[vec[target][i]] > d[target] + 1)
                d[vec[target][i]] = d[target] + 1;
            if (visited[vec[target][i]] == false)
                q.push(vec[target][i]);
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        if (d[i] == k)
        {
            cout << i << '\n';
            res++;
        }
    }
    if (res == 0)
        cout << -1;
}
