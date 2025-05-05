#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, num;
  int i = 0;
  priority_queue<int, vector<int>, greater<int>> pq;

  cin >> N;
  while (i < N*N)
  {
    cin >> num;
    pq.push(num);
    i++;
    if(pq.size() > N)
      pq.pop();
  }
  cout << pq.top();
}
