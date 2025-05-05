#include <iostream>
using namespace std;

int main()
{
  int num;
  int N = 2;
  cin >> num;
  if(num > 1)
  {
    while(num > 1)
    {
      if(num % N == 0)
      {
        cout << N << '\n';
        num /= N;
      }
      else
        N++;
    }
  }
  return(0);
}