#include <iostream>
using namespace std;
int gcd(int a, int b)
{
  int c;
  int res;
  c = a % b;
  if(c == 0)
    return(b);
  else
    res = gcd(b, c);
  return(res);
}

int main()
{
  int num1, num2, res;
  cin >> num1 >> num2;
  res = gcd(num1, num2);
  cout << res << '\n';
  cout << (num1*num2) / res;
  return(0);
}