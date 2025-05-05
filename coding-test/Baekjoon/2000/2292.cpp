#include <iostream>
using namespace std;

int main()
{
  int num;
  int i = 1;
  int res = 1;
  int seq = 1;
  cin >> num;

  while(num > seq)
  {
    res++;
    seq = seq + 6 * i;
    i++;
  }
  cout << res;
  return(0);
}