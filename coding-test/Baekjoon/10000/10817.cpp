#include <iostream>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
  fast;

  int a, b, c;
  cin >> a >> b >> c;
  if (a > b)
  {
    if (b > c)
      cout << b;
    else
    {
      if (a > c)
        cout << c;
      else
        cout << a;
    }
  }
  else
  {
    if (a > c)
      cout << a;
    else
    {
      if (b > c)
        cout << c;
      else
        cout << b;
    }
  }
}
