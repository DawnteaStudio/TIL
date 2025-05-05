#include <iostream>
#include <string>
#include <utility>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int main()
{
  fast;

  long long foo, bar;
  cin >> foo >> bar;

  if (foo == bar)
    cout << 1;
  else
    cout << 0;
}
