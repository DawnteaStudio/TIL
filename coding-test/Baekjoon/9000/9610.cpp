#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int num,x,y;
  int q1 = 0, q2 = 0, q3 = 0, q4 = 0, axis = 0;
  cin >> num;
  while (num--)
  {
    cin >> x >> y;
    if (x == 0 || y == 0)
      axis++;
    else if (x > 0)
    {
      x*y > 0 ? q1++ : q4++;
    }
    else
    {
      x*y > 0 ? q3++ : q2++;
    }
  }
  cout << "Q1: " << q1 << '\n';
  cout << "Q2: " << q2 << '\n';
  cout << "Q3: " << q3 << '\n';
  cout << "Q4: " << q4 << '\n';
  cout << "AXIS: " << axis << '\n';
}