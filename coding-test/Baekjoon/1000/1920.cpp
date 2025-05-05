#include <iostream>
#include <algorithm>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void  search(int comp[], int num, int N)
{
  int left = 0;
  int right = N - 1;
  int mid = (left + right) / 2;

  while(left <= right)
  {
    if (comp[mid] < num)
    {
      left = mid + 1;
      mid = (left + right) / 2;
    }
    else if (comp[mid] > num)
    {
      right = mid - 1;
      mid = (left + right) / 2;
    }
    else
    {
      cout << 1 << '\n';
        return ;
    }
  }
  cout << 0 << '\n';
}

int main()
{
  fast;

  int N, M;

  cin >> N;
  int *comp = new int[N];
  for (int i = 0; i < N; i++)
    cin >> comp[i];
  sort(comp, comp + N);

  cin >> M;
  int *arr = new int [M];
  for (int i = 0; i < M; i++)
    cin >> arr[i];

  for (int i = 0; i < M; i++)
    search(comp, arr[i], N);

  delete[] arr;
  delete[] comp;
}
