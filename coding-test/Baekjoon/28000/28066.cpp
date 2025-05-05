#include <iostream>
#include <string>
#include <deque>
using namespace std;

void kill_all(deque<int> &deq)
{
  while(deq.size() != 1)
    deq.pop_back();
}

void kill_K(deque<int> &deq, int K)
{
  int i = 1;
  int tmp = deq.front();
  deq.push_back(tmp);
  deq.pop_front();
  while(i < K)
  {
    deq.pop_front();
    i++;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, K;
  int i = 1;
  deque<int> deq;

  cin >> N >> K;

  while(i <= N)
  {
    deq.push_back(i);
    i++;
  }
  while (deq.size() != 1)
  {
    if(deq.size() >= K)
      kill_K(deq, K);
    else
      kill_all(deq);
  }
  cout << deq.front();
}
