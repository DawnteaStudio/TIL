#include <iostream>
using namespace std;

int main()
{
  int num, head, tail;
  int pos;
  int i = 0;
  cin >> num;

  while(num > 0)
  {
    i++;
    pos = num;
    num -= i;
  }

  if(i%2 == 0)
  {
    head = 1;
    tail = i;
    for(int j = 1; j < pos; j++)
    {
      head++;
      tail--;
    }
  }
  else
  {
    head = i;
    tail = 1;
    for(int j = 1; j < pos; j++)
    {
      head--;
      tail++;
    }
  }
  cout << head << "/" << tail;
  return(0);
}