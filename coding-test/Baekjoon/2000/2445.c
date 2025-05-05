#include <stdio.h>

int main()
{
  int num;
  scanf("%d", &num);
  for(int i = 1; i < num*2; i++)
  {
    for(int j = 0; j < num*2; j++)
    {
      if(i <= num)
      {
        if(j < i || j >= num*2 - i)
          printf("*");
        else
          printf(" ");
      }
      else
      {
        if(j < num*2 - i || j >= i)
          printf("*");
        else
          printf(" ");
      }
    }
    printf("\n");
  }
    return 0;
}