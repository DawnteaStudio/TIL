#include <stdio.h>

void	sum(int num);

int main(void)
{
	sum(10);
	sum(100);
	return (0);
}

void	sum(int num)
{
	int res = 0;

	for (int i = 1; i <= num; i++)
		res += i;
	printf("1부터 %d까지의 합은 %d입니다.\n", num, res);
}