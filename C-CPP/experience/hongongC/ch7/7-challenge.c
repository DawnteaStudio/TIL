#include <stdio.h>

int	rec_func(int n);

int main(void)
{
	printf("%d", rec_func(10));
}

int	rec_func(int n)
{
	int res;

	if (n == 1)
		return 1;
	res = (rec_func(n - 1) + n);
	return (res);
}