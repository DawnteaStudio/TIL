#include <stdio.h>

void	swap(int *pa, int *pb)
{
	int tmp;

	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

int main(void)
{
	int a = 10, b  = 20;

	swap(&a, &b);
	printf("a is : %d, b is : %d\n", a, b);

	return (0);
}