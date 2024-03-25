#include <stdio.h>

int main(void)
{
	int a;
	int *pa;

	pa = &a;
	*pa = 10;

	printf("pointer value : %d\n", *pa);
	printf("variable value : %d\n", a);

	return (0);
}