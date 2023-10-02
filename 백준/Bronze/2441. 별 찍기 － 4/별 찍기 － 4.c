#include <stdio.h>

int main()
{
  int num;
  int j;
  scanf("%d", &num);
  for(int i = 0; i < num; i++)
  {
    for(j = 0; j < i; j++)
    {
      printf(" ");
    }
    for(;j < num; j++)
    {
      printf("*");
    }
    printf("\n");
  }
	return 0;
}