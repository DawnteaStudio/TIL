#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int find_h(long left, long right, long goal, long trees[], long N)
{
  long mid, total;

  while (left <= right)
  {
    total = 0;
    mid = (left + right) / 2;
    for (int i = 0; i < N; i++)
    {
      if (trees[i] <= mid)
        continue;
      total += trees[i] - mid;
    }
    if (total >= goal)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return (right);
}

int main()
{
    fast;
    long N, M,tree, max = 0;
    cin >> N >> M;

    long *trees = new long[N];
    for (int i = 0; i < N; i++)
    {
      cin >> tree;
      if (tree > max)
        max = tree;
      trees[i] = tree;
    }
    cout << find_h(0, max, M, trees, N);

    delete[] trees;
    return (0);
}