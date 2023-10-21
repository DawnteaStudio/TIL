#include <iostream>
#include <string>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M, res = 0;
  int i = 0, j = 0;
  cin >> N >> M;
  N = N * 2;
  string str;
  cin >> str;
  char I = 'I';
  char O = 'O';

  while (i < M - 1)
  {
    j = 0;
    if (str[i] == I)
    {
      while (j < N && str[i+j] != str[i+j+1] && j + i < M - 1)
        j++;
      if (j == N)
        res++;
    }
    i++;
  }
  cout << res;
}
