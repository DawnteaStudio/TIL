#include <stdio.h>

int main()
{
  int num;
  scanf("%d", &num);
  int i = 1;
  while(i <= 9)
  {
    printf("%d * %d = %d\n", num, i, num*i);
    i++;
  }
	return 0;
}