#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;

void search(int len, int k)
{
  int len_now = len * 2 + (k + 3);

  if (N <= 3)
  {
    if (N == 1)
      cout << 'm';
    else
      cout << 'o';
  }
  else if (N > len_now)
    search(len_now, k+1);
  else
  {
    if (N <= len_now - len)
    {
      if (N == len + 1)
        cout << 'm';
      else
        cout << 'o';
    }
    else
    {
      N -= (len + k + 3);
      search(3, 1);
    }
  }
}

int main()
{
  fast;
  cin >> N;
  search(3, 1);
}