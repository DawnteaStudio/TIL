#include <stdio.h>

int main()
{
  int num, a, b;
  char c;

  scanf("%d", &num);
	for(int i = 0; i < num; i++)
  {
    scanf("%d%c%d", &a, &c, &b);
    printf("%d\n", a+b);
  }
	return 0;
}