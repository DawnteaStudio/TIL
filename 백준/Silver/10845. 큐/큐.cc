#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int size;
  int num;
  vector<int> res;
  string command;
  cin >> size;

  for(int i = 0; i < size; i++)
  {
    cin >> command;
    if(command == "push")
    {
      cin >> num;
      res.push_back(num);
    }
    else if(command == "pop")
    {
      if(res.empty())
        cout << -1 << '\n';
      else
      {
        cout << res[0] << '\n';
        res.erase(res.begin());
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