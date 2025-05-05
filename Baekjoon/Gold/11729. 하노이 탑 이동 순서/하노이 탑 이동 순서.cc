#include <iostream>
#include <string>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

string str = "";
int cnt = 0;

void hanoi(int plate, int start, int goal, int sup)
{
  if (plate == 1)
  {
    cnt++;
    str += to_string(start) + ' ' + to_string(goal) + '\n';
  }
  else
  {
    cnt++;
    hanoi(plate-1, start, sup, goal);
    str += to_string(start) + ' ' + to_string(goal) + '\n';
    hanoi(plate-1, sup, goal, start);
  }
}

int main()
{
  fast;

  int N;
  cin >> N;
  hanoi(N, 1, 3, 2);
  cout << cnt << '\n';
  cout << str;
}
