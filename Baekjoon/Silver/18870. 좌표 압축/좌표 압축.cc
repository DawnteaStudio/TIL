#include <iostream>
#include <map>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);


int main()
{
  fast;

  int N, num, index = 0;
  cin >> N;
  int *arr = new int[N];
  map<int, int> m;

  for (int i = 0; i < N; i++)
  {
    cin >> num;
    arr[i] = num;
    m[num] = 0;
  }
  for (auto iter = m.begin(); iter != m.end(); iter++)
  {
    iter->second = index;
    index++;
  }

  for (int i = 0; i < N; i++)
    cout << m[arr[i]] << ' ';
  delete[] arr;
}
