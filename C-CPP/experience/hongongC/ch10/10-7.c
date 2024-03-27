#include <stdio.h>

void	input_ary(double *pa, int size);
double	find_max(double *pa, int size);

int main(void)
{
	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]);

	input_ary(ary, size);
	max = find_max(ary, size);
	printf("배열의 최대값 : %.1lf\n", max);

	return (0);
}

void	input_ary(double *pa, int size)
{
	for (int i = 0; i < size; i++)
		scanf("%lf", pa++);
}

double	find_max(double *pa, int size)
{
	double max = 0;

	for (int i = 0; i < size; i++)
		max = pa[i] > max ? pa[i] : max;
	return (max);
}