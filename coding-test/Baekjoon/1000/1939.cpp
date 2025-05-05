#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m, start, goal; 

int main() {
    fast;
    cin >> n >> m;
    vector<vector<int> > world(n + 1);
    vector<vector<int> > weight(n + 1);

    for (int i = 0; i < m; i++)
    {
        int land1, land2, w;
        cin >> land1 >> land2 >> w;
        world[land2].push_back(land1);
        weight[land2].push_back(w);
        world[land1].push_back(land2);
        weight[land1].push_back(w);
    }
    cin >> start >> goal;

    int begin = 1, end = 1000000000;
    vector<bool> visited(n + 1, false);
    while (begin <= end)
    {
        int mid = (begin + end) / 2;
        bool flag = false;
        for (int i = 1; i <= n; i++)
            visited[i] = false;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int now = q.front();
            visited[now] = true;
            q.pop();
            if (now == goal)
            {
                flag = true;
                break;
            }
            else
            {
                int size = world[now].size();
                for (int i = 0; i < size; i++)
                {

                    if (visited[world[now][i]] == false && weight[now][i] >= mid)
                    {
                        q.push(world[now][i]);
                        visited[world[now][i]] = true;
                    }
                }
            }
        }
        if (flag)
            begin = mid + 1;
        else
            end = mid - 1;
    }
    cout << end;
}
