#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;
int white, blue;

void is_devide(int size, int start_y, int start_x, int **arr)
{
  int color;
  bool is_paper = true;

  if (size == 1)
  {
    if (arr[start_y][start_x] == 1)
      blue++;
    else
      white++;
    return ;
  }

  color = arr[start_y][start_x];
  for(int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (color != arr[start_y + i][start_x + j])
      {
        is_paper = false;
        break;
      }
    }
  }

  if (is_paper)
  {
    if (color == 1)
      blue++;
    else
      white++;
  }
  else
  {
    is_devide(size/2, start_y, start_x, arr);
    is_devide(size/2, start_y, start_x+(size/2), arr);
    is_devide(size/2, start_y+(size/2), start_x, arr);
    is_devide(size/2, start_y+(size/2), start_x+(size/2), arr);
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
  is_devide(N,0,0,arr);
  cout << white << '\n' << blue;

  for (int i = 0; i < N; i++)
    delete[] arr[i];
  delete[] arr;
}