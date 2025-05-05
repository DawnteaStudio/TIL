#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, range, dmg, C, zombie, danger = 0;
  int use_bomb = 0;
  queue<int> bomb;
  cin >> N >> range >> dmg >> C;

  for (int i = 1; i <= N; i++)
  {
    cin >> zombie;
    if (i <= range)
    {
      if (use_bomb != 0)
      {
        if (i - bomb.front() >= range)
        {
          bomb.pop();
          use_bomb--;
        }
      }
      if (zombie + (use_bomb * dmg) > dmg * i)
      {
        bomb.push(i);
        use_bomb++;
        danger++;
      }
      else
        continue;
    }
    else
    {
      if (use_bomb != 0)
      {
        if (i - bomb.front() >= range)
        {
          bomb.pop();
          use_bomb--;
        }
      }
      if (zombie + (use_bomb * dmg) > dmg * range)
      {
        bomb.push(i);
        use_bomb++;
        danger++;
      }
      else
        continue;
    }
  }
  if (C >= danger)
    cout << "YES";
  else
    cout << "NO";
}
