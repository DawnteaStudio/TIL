#include <iostream>
#include <cmath>
using namespace std;

int is_prime(int num)
{
  if (num < 2)
    return 0;
  for(int i = 2; i < num; i++)
  {
    if(num % i == 0)
      return(0);
  }
  return(1);
}

int main()
{
  int cases;
  int num;
  int res = 0;

  cin >> cases;
  for(int i = 0; i < cases; i++)
  {
    cin >> num;
    if (is_prime(num) == 1)
      res++;
  }
  cout << res;
  return(0);
}