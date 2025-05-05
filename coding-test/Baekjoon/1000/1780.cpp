#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;
int MINUS, ZERO, PLUS;

void is_devide(int size, int start_y, int start_x, int **arr)
{
  int data;
  bool is_done = true;
  if (size == 1)
  {
    if (arr[start_y][start_x] == -1)
      MINUS++;
    else if (arr[start_y][start_x] == 0)
      ZERO++;
    else
      PLUS++;
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
  {
    if (arr[start_y][start_x] == -1)
      MINUS++;
    else if (arr[start_y][start_x] == 0)
      ZERO++;
    else
      PLUS++; 
  }
  else
  {
    is_devide(size/3, start_y, start_x, arr);
    is_devide(size/3, start_y, start_x+(size/3), arr);
    is_devide(size/3, start_y, start_x+(size/3)*2, arr);
    is_devide(size/3, start_y+(size/3), start_x, arr);
    is_devide(size/3, start_y+(size/3), start_x+(size/3), arr);
    is_devide(size/3, start_y+(size/3), start_x+(size/3)*2, arr);
    is_devide(size/3, start_y+(size/3)*2, start_x, arr);
    is_devide(size/3, start_y+(size/3)*2, start_x+(size/3), arr);
    is_devide(size/3, start_y+(size/3)*2, start_x+(size/3)*2, arr);
  }
}

int main()
{
  fast;

  cin >> N;
  int **arr = new int*[N];
  for (int i = 0; i < N; i++)
    arr[i] = new int[N];
  
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cin >> arr[i][j];
  }
  is_devide(N, 0, 0, arr);
  cout << MINUS << '\n' << ZERO << '\n' << PLUS;
  for (int i = 0; i < N; i++)
    delete[] arr[i];
  delete[] arr;
}