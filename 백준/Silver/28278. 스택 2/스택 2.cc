#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int num;
  cin >> num;

  stack<int> v;

  for (int i = 0; i < num; i++)
  {
    int command;

    cin >> command;
    if (command == 5)
    {
      if (v.empty())
        cout << -1 << '\n';
      else
        cout << v.top() << '\n';
    }
    else if (command == 3)
    {
      cout << v.size() << '\n';
    }
    else if (command == 4)
    {
      if (v.empty())
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
    else if (command == 2)
    {
      if (v.empty())
        cout << -1 << '\n';
      else
      {
        cout << v.top() << '\n';
        v.pop();
      }
    }
    else if (command == 1)
    {
      int num;

      cin >> num;
      v.push(num);
    }
  }
}