#include <iostream>
#include <string>
#include <cmath>
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
  if (N < 63)
    cout << (long long)(pow(2, N) - 1) << '\n';
  else
  {
    str = to_string(pow(2, N));
    int x = str.find('.');
    str = str.substr(0, x);
    str[str.length() - 1] -= 1;
    cout << str;
  }
  if (N <= 20)
  {
    hanoi(N, 1, 3, 2);
    cout << str;
  }
}
