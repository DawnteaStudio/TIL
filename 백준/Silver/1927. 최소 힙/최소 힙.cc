#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int cases;
  int command;
  priority_queue<int, vector<int>, greater<int>> heap;

  cin >> cases;
  while(cases--)
  {
    cin >> command;
    if (command == 0)
    {
      if (heap.empty())
        cout << 0 << '\n';
      else
      {
        cout << heap.top() << '\n';
        heap.pop();
      }
    }
    else
      heap.push(command);
  }
}
