#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N;

void make_star(int size, char *arr[], int start_y, int start_x, int blank)
{
  if (size == 3 && blank != 1)
  {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
      {
        if (i == 1 && j == 1)
          arr[start_y + i][start_x + j] = ' ';
        else
          arr[start_y + i][start_x + j] = '*';
      }
  }
  else if(blank == 1)
  {
    for(int i = 0; i < size; i++)
      for(int j = 0; j < size; j++)
        arr[start_y + i][start_x + j] = ' ';
  }
  else
  {
    make_star(size/3, arr, start_y, start_x, 0);
    make_star(size/3, arr, start_y, start_x + size/3, 0);
    make_star(size/3, arr, start_y, start_x + (size/3)*2, 0);
    make_star(size/3, arr, start_y + size/3, start_x, 0);
    make_star(size/3, arr, start_y + size/3, start_x + size/3, 1);
    make_star(size/3, arr, start_y + size/3, start_x + (size/3)*2, 0);
    make_star(size/3, arr, start_y + (size/3)*2, start_x, 0);
    make_star(size/3, arr, start_y + (size/3)*2, start_x + size/3, 0);
    make_star(size/3, arr, start_y + (size/3)*2, start_x + (size/3)*2, 0);
  }
}

int main()
{
  fast;
  cin >> N;
  
  char **arr = new char*[N];
  for (int i = 0; i < N; i++)
    arr[i] = new char[N];
  make_star(N, arr, 0, 0, 0);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << arr[i][j];
    cout << '\n';
  }
}