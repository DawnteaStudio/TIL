#include <iostream>
#include <vector>
#include <queue>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<pair<int, int> > v[100001];
bool visited[10001] = {false};
int N, M;

int solve(int start, int goal, int max)
{
  queue<int> q;
  int left = 1;
  int right = max;
  int mid;
  int start_tmp;
  while (left <= right)
  {
    q.push(start);
    mid = (left + right) / 2;
    for (int i = 1; i <= N; i++)
      visited[i] = false;
    visited[start] = true;
    while (!q.empty())
    {
      start_tmp = q.front();
      q.pop();
      for (int i = 0; i < v[start_tmp].size(); i++)
      {
        if (v[start_tmp][i].second < mid)
          continue;
        else if(visited[v[start_tmp][i].first] == false)
        {
          q.push(v[start_tmp][i].first);
          visited[v[start_tmp][i].first] = true;
        }
      }
    }
    if (visited[goal] == true)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return (right);
}

int main()
{
  fast;
  int pos1, pos2, weight, max = 0;
  int start, goal;
  cin >> N >> M;

  for (int i = 0; i < M; i++)
  {
    cin >> pos1 >> pos2;
    cin >> weight;
    if (max < weight)
      max = weight;
    v[pos1].push_back({pos2, weight});
    v[pos2].push_back({pos1, weight});
  }
  cin >> start >> goal;
  cout << solve(start, goal, max);
}