#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
  fast;

  int N, M, target, res = 0;
  int start, end;
  cin >> N >> M;;

  vector<vector<int> > v(N+1, vector<int>());
  vector<int> corr(N+1, false);
  queue<int> next;

  for (int i = 0; i < M; i++)
  {
    cin >> start >> end;
    v[start].push_back(end);
    v[end].push_back(start);
  }

  corr[1] = true;
  next.push(1);

  while(!next.empty())
  {
    target = next.front();
    next.pop();
    for (int i = 0; i < v[target].size(); i++)
    {
      if (corr[v[target][i]] == false)
      {
        res++;
        corr[v[target][i]] = true;
        next.push(v[target][i]);
      }
    }
  }
  cout << res;
}
