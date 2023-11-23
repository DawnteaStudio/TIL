#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;

void is_devide(int size, int start_y, int start_x, char **arr)
{
  char data;
  bool is_done = true;
  if (size == 1)
  {
    cout << arr[start_y][start_x];
    return ;
  }
  data = arr[start_y][start_x];
  for(int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (data != arr[start_y + i][start_x + j])
      {
        is_done = false;
        break;
      }
    }
  }
  if (is_done)
    cout << arr[start_y][start_x];
  else
  {
    cout << '(';
    is_devide(size/2, start_y, start_x, arr);
    is_devide(size/2, start_y, start_x+(size/2), arr);
    is_devide(size/2, start_y+(size/2), start_x, arr);
    is_devide(size/2, start_y+(size/2), start_x+(size/2), arr);
    cout << ')';
  }
}

int main()
{
  fast;

  cin >> N;
  char **arr = new char*[N];
  string line;
  for (int i = 0; i < N; i++)
    arr[i] = new char[N];
  
  for (int i = 0; i < N; i++)
  {
    cin >> line;
    for (int j = 0; j < N; j++)
      arr[i][j] = line[j];
  }
  is_devide(N, 0, 0, arr);
  for (int i = 0; i < N; i++)
    delete[] arr[i];
  delete[] arr;
}