#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
int x, y, m = 0;

void dfs(char v[20][20], bool alpha[], int start_y, int start_x, int cnt)
{
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int new_x, new_y;
  int last_node = 1;

  for (int i = 0; i < 4; i++)
  {
    new_x = dx[i] + start_x;
    new_y = dy[i] + start_y;

    if (new_x < 0 || new_y < 0 || new_x >= x || new_y >= y || alpha[v[new_y][new_x] - 'A'])
      continue;
    if (alpha[v[new_y][new_x] - 'A'] == false)
    {
      last_node = 0;
      alpha[v[new_y][new_x] - 'A'] = true;
      dfs(v, alpha, new_y, new_x, cnt + 1);
      alpha[v[new_y][new_x] - 'A'] = false;
    }
  }
  if (last_node == 1)
    m = cnt > m ? cnt : m;
}

int main()
{
  fast;

  bool alpha[26] = {false};
  string str;
  cin >> y >> x;
  char v[20][20];

  for (int i = 0; i < y; i++)
  {
    cin >> str;
    for (int j = 0; j < x; j++)
      v[i][j] = str[j];
  }
  alpha[v[0][0] - 'A'] = true;
  dfs(v, alpha, 0, 0, 1);
  cout << m;
}
