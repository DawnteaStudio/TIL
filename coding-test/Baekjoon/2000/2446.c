#include <stdio.h>

int main()
{
  int num;
  scanf("%d", &num);
  for(int i = 0; i < num*2-1; i++)
  {
    for(int j = 0; j < num*2-1; j++)
    {
      if(i < num)
      {
        if(j < i)
          printf(" ");
        //else if(j >= num*2-(i+1))
        //  continue;
        else if(j < num*2 -1 -i)
          printf("*");
      }
      else
      {
        if(j < num*2-1 - (i+1))
          printf(" ");
        else if(j <= i)
          printf("*");
        //else
          //printf("*");
      }
    }
    printf("\n");
  }
    return 0;
}