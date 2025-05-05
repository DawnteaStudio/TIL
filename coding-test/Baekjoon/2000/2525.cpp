#include <iostream>
#include <string>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);


int main()
{
  fast;

  int h, m, t;
  cin >> h >> m >> t;

  h += t/60;
  m += t%60;

  h += m/60;
  m %= 60;
  h %= 24;
  cout << h << ' ' << m;
}
