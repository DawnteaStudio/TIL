#include <stdio.h>

int main()
{
  int num;
  int j = 0;
  scanf("%d", &num);
  for(int i = num; i > 0; i--)
  {
    for(j = 0; j < i - 1; j++)
    {
      printf(" ");
    }
    for(; j < num; j++)
    {
      printf("*");
    }
    printf("\n");
  }
    return 0;
}