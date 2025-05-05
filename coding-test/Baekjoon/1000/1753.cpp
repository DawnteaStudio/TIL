#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second > b.second)
        {
            if (b.second == -1)
                return false;
            return true;
        }
        if (a.second == -1)
            return true;
        return false;
    }
};


int main() {
    fast;
    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int> > > vec(v + 1);
    vector<int> dist(v + 1, -1);
    vector<bool> visited(v + 1, false);

    int start;
    cin >> start;
    dist[start] = 0;

    int s, d, w;
    for (int i = 0; i < e; i++)
    {
        cin >> s >> d >> w;
        vec[s].push_back(make_pair(d, w));
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
    q.push(make_pair(start, 0));
    while (!q.empty())
    {
        int now = q.top().first;
        int cost = q.top().second;
        q.pop();

        if (visited[now] == false)
        {
            visited[now] = true;
            int size = vec[now].size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> node = vec[now][i];
                if (dist[node.first] == -1)
                    dist[node.first] = dist[now] + node.second;
                else if (dist[node.first] > dist[now] + node.second)
                    dist[node.first] = dist[now] + node.second;
                q.push(make_pair(node.first, dist[node.first]));
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == -1)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
}