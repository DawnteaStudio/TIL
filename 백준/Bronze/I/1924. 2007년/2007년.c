#include <stdio.h>

int main()
{
  char* strArr[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  int month, date;
  int res = 0;
  scanf("%d%d", &month, &date);
  for(int i = 1; i < month; i++)
  {
    if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
      res += 31;
    else if(i == 2)
      res += 28;
    else
      res += 30;
  }
  res += date - 1;
  printf("%s", strArr[res % 7]);
	return 0;
}