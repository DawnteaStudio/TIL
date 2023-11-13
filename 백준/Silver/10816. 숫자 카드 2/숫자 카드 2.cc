#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

void search(int comp[], int arr[], int N, int M)
{
  map<int, int> m;
  int cnt = 0;
  int left = 0;
  int tmp;
  int right = N - 1;
  int mid = (left + right) / 2;

  for (int i = 0; i < M; i++)
  {
    if (m.find(arr[i]) != m.end())
    {
      cout << m[arr[i]] << ' ';
      continue;
    }
    left = 0;
    right = N - 1;
    mid = (left + right) / 2;
    cnt = 0;
    while (left <= right)
    {
      if (comp[mid] < arr[i])
      {
        left = mid + 1;
        mid = (left + right) / 2;
      }
      else
      {
        right = mid - 1;
        mid = (left + right) / 2;
      }
    }
    tmp = left;
    while (comp[tmp] == arr[i])
    {
      tmp++;
      cnt++;
    }
    m.insert({arr[i],cnt});
    cout << cnt << ' ';
  }
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
  int *arr = new int[M];
  for (int i = 0; i < M; i++)
    cin >> arr[i];
  search(comp, arr, N, M);

  delete[] arr;
  delete[] comp;
}
