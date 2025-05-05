#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_h(int left, int right, int budget[], int N, int M)
{
  int mid, tmp, total;
  while (left <= right)
  {
    mid = (left + right) / 2;
    tmp = mid;
    total = 1;
    for (int i = 0; i < N; i++)
    {
      if (tmp < budget[i])
      {
        tmp = mid;
        tmp -= budget[i];
        total++;
      }
      else
        tmp -= budget[i];
    }
    if (total > M)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return (left);
}

int main()
{
  fast;
  int N, M, max = 0;
  cin >> N >> M;

  int *budget = new int[N];
  for (int i = 0; i < N; i++)
  {
    cin >> budget[i];
    if (max < budget[i])
      max = budget[i];
  }
  cout << find_h(max, 10000 * N, budget, N, M);

  delete[] budget;
  return (0);
}