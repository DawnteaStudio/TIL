#include <iostream>
#include <string>
#include <utility>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
  fast;

  int N, M;
  int res = 0, len, i = 0;
  string str;
  cin >> N >> M >>str;

  while (i < M)
  {
    if (str[i] == 'I')
    {
      len = 1;
      while (i + 1 < M && str[i] != str[i + 1])
      {
        len++;
        i++;
      }
      if (len >=  N * 2 + 1)
        res += (len - (N * 2 + 1)) / 2 + 1;
      i++;
    }
    else
      i++;
  }
  cout << res;
}
