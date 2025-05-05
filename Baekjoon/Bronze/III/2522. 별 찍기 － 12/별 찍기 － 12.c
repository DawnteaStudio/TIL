#include <stdio.h>

int main()
{
  int num;
  scanf("%d", &num);
  for(int i = 1; i <= num*2-1; i++)
  {
    for(int j = num; j > 0; j--)
    {
      if(i <= num)
      {
        if(j > i)
          printf(" ");
        else
          printf("*");
      }
      else
      {
        if(num - j < i - num)
          printf(" ");
        else
          printf("*");
      }
    }
    printf("\n");
  }
	return 0;
}