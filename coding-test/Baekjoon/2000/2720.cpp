#include <iostream>
using namespace std;

int main()
{
  int cases;
  int num;

  cin >> cases;
  for(int i = 0; i < cases; i++)
  {
    cin >> num;
    cout << num/25 << ' ';
    num %= 25;
    cout << num/10 << ' ';
    num %= 10;
    cout << num/5 << ' ';
    num %= 5;
    cout << num/1;
    if (i != cases - 1)
      cout << '\n';
  }
  return(0);
}