#include <stdio.h>

int main(void)
{
	int arr[5];
	int total = 0;
	double avg;

	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < 5; i++)
	{
		total += arr[i];
		printf("%5d", arr[i]);
	}
	printf("\n");
	avg = total / 5.;

	printf("평균 : %.1lf\n", avg);
	return (0);
}