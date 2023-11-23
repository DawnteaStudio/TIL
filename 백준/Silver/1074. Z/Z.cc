#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N, goal_y, goal_x;
int cnt;

int ft_pow(int num)
{
  int res = 1;

  for (int i = 0; i < num; i++)
    res *= 2;
  return (res);
}

void search(int n, int start_y, int start_x)
{
  int section = 0;

  if (n == 1)
  {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j <2; j++)
      {
        if (start_y+i == goal_y && start_x+j == goal_x)
          return ;
        cnt++;
      }
  }
  else
  {
    if (start_y + ft_pow(n-1) <= goal_y)
    {
      start_y = start_y + ft_pow(n-1);
      section += 2;
    }
    if (start_x + ft_pow(n-1) <= goal_x)
    {
      start_x = start_x + ft_pow(n-1);
      section += 1;
    }
    cnt += section * ft_pow(n-1) * ft_pow(n-1);
    search(n-1, start_y, start_x);
  }
}

int main()
{
  fast;

  cin >> N >> goal_y >> goal_x;

  search(N, 0, 0);
  cout << cnt;
}