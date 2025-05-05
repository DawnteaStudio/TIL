#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int size, cnt, chk_cnt = 0;
  queue<int> q;
  vector<int> res;
  cin >> size >> cnt;

  for(int i = 1; i <= size; i++)
    q.push(i);
  while(!q.empty())
  {
    while (chk_cnt != cnt-1)
    {
      q.push(q.front());
      q.pop();
      chk_cnt++;
    }
    res.push_back(q.front());
    q.pop();
    chk_cnt = 0;
  }
  cout << '<';
  for(int i = 0; i < res.size(); i++)
  {
    if(i != res.size() - 1)
      cout << res[i] << ", ";
    else
      cout << res[i];
  }
  cout << ">";
}