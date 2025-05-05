#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int N = 0;
char graph[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int y, int x, bool visit[][100])
{
  int new_y, new_x, res = 0;
  char color = graph[y][x];

  for (int i = 0; i < 4; i++)
  {
    new_y = dy[i] + y;
    new_x = dx[i] + x;
    if (new_y < 0 || new_x < 0 || new_y >= N || new_x >= N)
      continue;
    if (visit[new_y][new_x] == false && graph[new_y][new_x] == color)
    {
      visit[new_y][new_x] = true;
      dfs(new_y, new_x, visit);
    }
  }
}

void rg_dfs(int y, int x, bool visit2[][100])
{
  int new_y, new_x, res = 0;
  char color = graph[y][x];

  if (color == 'B')
  {
    for (int i = 0; i < 4; i++)
    {
      new_y = dy[i] + y;
      new_x = dx[i] + x;
      if (new_y < 0 || new_x < 0 || new_y >= N || new_x >= N)
        continue;
      if (visit2[new_y][new_x] == false && graph[new_y][new_x] == color)
      {
        visit2[new_y][new_x] = true;
        rg_dfs(new_y, new_x, visit2);
      }
    }
  }
  else
  {
    for (int i = 0; i < 4; i++)
    {
      new_y = dy[i] + y;
      new_x = dx[i] + x;
      if (new_y < 0 || new_x < 0 || new_y >= N || new_x >= N)
        continue;
      if (visit2[new_y][new_x] == false && (graph[new_y][new_x] == 'R' || graph[new_y][new_x] == 'G'))
      {
        visit2[new_y][new_x] = true;
        rg_dfs(new_y, new_x, visit2);
      }
    }
  }
}
int main()
{
  fast;
  
  int rgb = 0, rg_b = 0;
  cin >> N;
  bool visit[100][100] = {false};
  bool visit2[100][100] = {false};

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cin >> graph[i][j];
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (visit[i][j] == false)
      {
        visit[i][j] = true;
        rgb++;
        dfs(i, j, visit);
      }
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (visit2[i][j] == false)
      {
        visit2[i][j] = true;
        rg_b++;
        rg_dfs(i, j, visit2);
      }
    }
  }
  cout << rgb << ' ' << rg_b;
}
