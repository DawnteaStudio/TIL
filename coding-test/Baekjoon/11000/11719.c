#include <stdio.h>

int main()
{
  char str[101];
  while(gets(str) != '\0')
  {
    printf("%s\n", str);
  }
    return 0;
}