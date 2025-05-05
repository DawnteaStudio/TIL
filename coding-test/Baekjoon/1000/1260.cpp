#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void dfs(int v, vector<vector<int>> graph, vector<bool> &visited)
{
  cout << v << ' ';
  visited[v-1] = true;
  for(int i = 0; i < graph[v-1].size(); i++)
  {
    if (visited[graph[v-1][i]] == false)
      dfs(graph[v-1][i]+1, graph, visited);
  }
}

void bfs(int v, vector<vector<int>> graph, vector<bool> &visited)
{
  vector<int> q;
  int i = 0;
  q.push_back(v-1);
  visited[v-1] = true;
  while(i < q.size())
  {
    cout << q[i] + 1 << ' ';
    v = q[i] + 1;
    for (int j = 0; j < graph[v-1].size(); j++)
    {
      if (visited[graph[v-1][j]] == false)
      {
        q.push_back(graph[v-1][j]);
        visited[graph[v-1][j]] = true;
      }
    }
    i++;
  }
}

int main()
{
  fast;

  int N, M, V, i = 0;
  cin >> N >> M >> V;
  vector<bool> dfs_visited(N, false);
  vector<bool> bfs_visited(N, false);
  vector<vector<int>> graph(N, vector<int>());
  int x, y;

  while (i < M)
  {
    cin >> x >> y;
    graph[x-1].push_back(y-1);
    graph[y-1].push_back(x-1);
    i++;
  }
  for (int k = 0; k < graph.size(); k++)
    sort(graph[k].begin(), graph[k].end());
  dfs(V, graph, dfs_visited);
  cout << '\n';
  bfs(V, graph, bfs_visited);
}
