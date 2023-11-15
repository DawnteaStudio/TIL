#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_h(int left, int right, int city[], int N, int M)
{
  int mid, total;

  while (left <= right)
  {
    mid = (left + right) / 2;
    total = 0;
    for (int i = 0; i < N; i++)
    {
      if (city[i] <= mid)
        total += city[i];
      else
        total += mid;
    }
    if (total <= M)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return (right);
}

int main()
{
  fast;
  int N, M, budget, max = 0;
  cin >> N;

  int *city = new int[N];
  for (int i = 0; i < N; i++)
  {
    cin >> budget;
    if (budget > max)
      max = budget;
    city[i] = budget;
  }
  cin >> M;
  cout << find_h(0, max, city, N, M);

  delete[] city;
  return (0);
}