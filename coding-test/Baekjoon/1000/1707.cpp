#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int v, e, a, b;
        bool flag = true;
        cin >> v >> e;
        vector<vector<int> > graph(v + 1);
        for (int j = 0; j < e; j++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<vector<int> > bip(2, vector<int>(v + 1, 0));
        vector<int> visited(v + 1, 0);

        bip[0][1]++;
        visited[1]++;
        queue<pair<int, int> > q;
        q.push({1, 1});

        while (!q.empty()) {
            int now = q.front().first;
            int dir = q.front().second;
            visited[now]++;
            q.pop();

            int size = graph[now].size();
            for (int j = 0; j < size; j++) {
                if (visited[graph[now][j]] == 0) {
                    if (bip[(dir + 1) % 2][graph[now][j]]) {
                        flag = false;
                        break;
                    }
                    bip[dir][graph[now][j]]++;
                    q.push({graph[now][j], (dir + 1) % 2});
                }
            }
            if (flag == false)
                break;
            if (q.size() == 0) {
                for (int j = 1; j <= v; j++) {
                    if (visited[j] == 0) {
                        q.push({j, 1});
                        break;
                    }
                }
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
