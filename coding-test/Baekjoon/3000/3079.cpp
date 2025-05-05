#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

unsigned long find_h(unsigned long left, unsigned long right, unsigned long inspect[], unsigned long N, unsigned long M)
{
  unsigned long mid, cnt;
  while (left <= right)
  {
    mid = (left + right) / 2;
    cnt = 0;
    for (long i = 0; i < N; i++)
      cnt += mid / inspect[i];
    if (cnt < M)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return (left);
}

int main()
{
  fast;
  unsigned long N, M, max = 0;
  cin >> N >> M;

  unsigned long * inspect = new unsigned long[N];
  for (int i = 0; i < N; i++)
  {
    cin >> inspect[i];
    if (max < inspect[i])
      max = inspect[i];
  }
  cout << find_h(0, max * M, inspect, N, M);

  delete[] inspect;
  return (0);
}