#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  string N;
  int num;
  int res = 0;
  int k = 0;

  cin >> N >> num;
  for(int i = N.length() - 1; i >= 0; i--)
  {
    if(N[i] >= 'A')
      res += (N[i] - 'A' + 10) * pow(num, k);
    else
      res += (N[i] - '0') * pow(num, k);
    k++;
  }
  cout << res;
  return(0);
}