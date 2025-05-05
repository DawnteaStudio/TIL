#include <iostream>
using namespace std;

int main()
{
  int num;
  int res = 2;

  cin >> num;
  for(int i = 1; i <= num; i++)
  {
    res = 2 * res -1;
  }
  cout << res * res;
  return(0);
}