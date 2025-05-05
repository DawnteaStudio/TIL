#include <iostream>
#include <string>
using namespace std;

string itoa(int num, int base)
{
  string res;
  string reverse_res;
  char c;

  while(num > 0)
  {
    if(num % base >= 10)
      c = (num % base) + 'A' - 10;
    else
      c = (num % base) + '0';
    res += c;
    num /= base;
  }
  for(int i = res.length()-1; i >= 0; i--)
    reverse_res += res[i];
  return(reverse_res);
}

int main()
{
  string N;
  int num;
  int base;

  cin >> num >> base;
  N = itoa(num, base);
  cout << N;
  return(0);
}