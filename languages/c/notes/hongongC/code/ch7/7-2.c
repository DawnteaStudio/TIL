#include <stdio.h>

int get_num(void);

int main(void)
{
	int result;

	result = get_num();
	printf("res is : %d\n", result);
	return (0);
}

int get_num(void)
{
	int num;

	printf("input positive num : ");
	scanf("%d", &num);
	while (num <= 0)
	{
		printf("input positive num not negative or 0 : ");
		scanf("%d", &num);
	}
	return (num);
}