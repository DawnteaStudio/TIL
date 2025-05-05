#include <stdio.h>

int main()
{
  char nums[100];
  int num;
  int res = 0;
  scanf("%d", &num);
  scanf("%s", nums);
  for(int i = 0; i < num; i++)
  {
    res += nums[i] - '0';
  }
  printf("%d", res);
    return 0;
}