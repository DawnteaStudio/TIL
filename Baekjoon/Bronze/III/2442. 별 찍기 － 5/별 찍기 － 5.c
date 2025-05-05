#include <stdio.h>

int main()
{
  int num;
  int j;
  int k;
  scanf("%d", &num);
  for(int i = 0; i < num; i++)
  {
    for(j = num; j > i+1; j--)
    {
      printf(" ");
    }
    for(k = 0;k < i*2 + 1; k++)
    {
      printf("*");
    }
    printf("\n");
  }
	return 0;
}