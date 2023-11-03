#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <vector>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void bfs(int N, int M, vector<vector<bool> > &visited, vector<vector<char> > v, queue<pair<int, int> > &que)
{
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};
  int x;
  int y;
  vector<vector<int> > dist(N, vector<int>(M, 1));
  pair<int, int> node;

  while (!que.empty())
  {
    node = que.front();
    que.pop();
    for(int i = 0; i < 4; i++)
    {
      y = dy[i] + node.first;
      x = dx[i] + node.second;
      if (y < 0 || x < 0 || y >= N || x >= M)
        continue;
      if (visited[y][x] == false && v[y][x] == '1')
      {
        que.push(make_pair(y, x));
        dist[y][x] = dist[node.first][node.second] + 1;
        visited[y][x] = true;
      }
    }
  }
  cout << dist[N-1][M-1];
}

int main()
{
  fast;

  int N, M, res = 0;
  string str;
  cin >> N >> M;;

  vector<vector<char> > v(N, vector<char>(M));
  vector<vector<bool> > visited(N, vector<bool>(M, false));
  queue<pair<int, int> > que;

  for (int i = 0; i < N; i++)
  {
    cin >> str;
    for (int j = 0; j < M; j++)
      v[i][j] = str[j];
  }

  que.push(make_pair(0, 0));
  bfs(N, M, visited, v, que);
}
