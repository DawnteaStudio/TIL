#include <stdio.h>

int main()
{
  int num;
  int n;
  int max = -1000000;
  int min = 1000000;
  scanf("%d", &num);
  for(int i = 0; i < num; i++)
  {
    scanf("%d", &n);
    if(n < min)
      min = n;
    if (n > max)
      max = n;
  }
  printf("%d %d", min, max);
    return 0;
}