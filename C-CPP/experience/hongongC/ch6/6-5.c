#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;

	for (i = 1; i <= 10; i++)
	{
		sum += i;
		if (sum > 30) break;
	}
	printf("prefix_sum : %d\n", sum);
	printf("last added : %d\n", i);
	return (0);
}