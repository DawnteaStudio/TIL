#include <iostream>
#include <string>
#include <queue>
using namespace std;

void fill_gift(priority_queue<int> &pq, int command)
{
  int present;
  int i = 0;
  
  while (i < command)
  {
    cin >> present;
    pq.push(present);
    i++;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, command;
  int i = 0;
  priority_queue<int> pq;

  cin >> N;
  while (i < N)
  {
    cin >> command;
    if (command == 0)
    {
      if (pq.size() == 0)
        cout << -1 << '\n';
      else
      {
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
    else
      fill_gift(pq, command);
    i++;
  }
}
