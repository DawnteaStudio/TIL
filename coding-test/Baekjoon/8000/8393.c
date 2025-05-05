#include <stdio.h>

int main()
{
  int num;
  int res = 0;
  scanf("%d", &num);
  for(int i = 1; i <= num; i++)
  {
    res += i;
  }
  printf("%d", res);
    return 0;
}