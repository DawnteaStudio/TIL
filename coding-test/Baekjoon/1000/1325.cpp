#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m, a, b, res = 0;
    cin >> n >> m;

    vector<vector<int> > vec(n + 1);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vec[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        int tmp = 1;
        vector<int> visited(n + 1, 0);

        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            int size = vec[now].size();
            for (int j = 0; j < size; j++) {
                if (visited[vec[now][j]] == 0) {
                    visited[vec[now][j]]++;
                    tmp++;
                    q.push(vec[now][j]);
                }
            }
        }
        if (tmp > res)
            res = tmp;
        cnt[i] = tmp;
    }

    for (int i = 1; i <= n; i++) {
        if (res == cnt[i])
            cout << i << " ";
    }
}
