#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int size;
  int num;
  queue<int> res;
  string command;
  cin >> size;

  for(int i = 0; i < size; i++)
  {
    cin >> command;
    if(command == "push")
    {
      cin >> num;
      res.push(num);
    }
    else if(command == "pop")
    {
      if(res.empty())
        cout << -1 << '\n';
      else
      {
        cout << res.front() << '\n';
        res.pop();
      }
    }
    else if(command == "size")
    {
      cout << res.size() << '\n';
    }
    else if(command == "empty")
    {
      if (res.empty())
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
    else if(command == "front")
    {
      if (res.empty())
        cout << -1 << '\n';
      else
        cout << res.front() << '\n';
    }
    else
    {
      if (res.empty())
        cout << -1 << '\n';
      else
        cout << res.back() << '\n';
    }
  }
}
