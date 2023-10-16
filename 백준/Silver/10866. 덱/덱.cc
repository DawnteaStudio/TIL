#include <deque>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int size;
  int num;
  deque<int> res;
  string command;
  cin >> size;

  for(int i = 0; i < size; i++)
  {
    cin >> command;
    if(command == "push_front")
    {
      cin >> num;
      res.push_front(num);
    }
    else if(command == "push_back")
    {
      cin >> num;
      res.push_back(num);
    }
    else if(command == "pop_front")
    {
      if(res.empty())
        cout << -1 << '\n';
      else
      {
        cout << res.front() << '\n';
        res.pop_front();
      }
    }
    else if(command == "pop_back")
    {
      if(res.empty())
        cout << -1 << '\n';
      else
      {
        cout << res.back() << '\n';
        res.pop_back();
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
