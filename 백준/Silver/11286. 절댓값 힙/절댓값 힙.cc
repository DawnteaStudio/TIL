#include <iostream>
#include <string>
#include <queue>
using namespace std;

int ft_abs(int num)
{
  num = num > 0 ? num : -num;
  return (num);
}

struct comp{
  bool operator() (int a, int b){
    bool res = false;
    if (ft_abs(a) > ft_abs(b))
      res = true;
    else if (ft_abs(a) == ft_abs(b))
    {
      if(a > b)
        res = true;
      else
        res = false;
    }

    return res;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int cases;
  int command;
  priority_queue<int, vector<int>, comp> heap;

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
