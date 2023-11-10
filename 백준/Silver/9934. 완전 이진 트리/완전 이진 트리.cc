#include <iostream>
#include <cmath>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

int tmp;

void reculsive(int arr[], int start, int depth, int height)
{
  if (depth != 1)
    reculsive(arr, start + pow(2, height - 1), depth - 1, height + 1);
  for (int i = 0; i < pow(2, depth - 1); i++)
  {
    cout << arr[start] << ' ';
    start += pow(2, height);
  }
  cout << '\n';
}

int main()
{
  fast;

  int depth;
  cin >> depth;

  tmp = pow(2, depth);
  int *arr = new int[tmp - 1];
  
  for (int i = 0; i < tmp-1; i++)
    cin >> arr[i];
  reculsive(arr, 0, depth, 1);
  delete[] arr;
}
