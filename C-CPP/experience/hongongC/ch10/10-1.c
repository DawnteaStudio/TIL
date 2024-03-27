#include <stdio.h>

int main(void)
{
	int ary[3];
	*(ary + 0) = 10;
	*(ary + 1) = *(ary + 0) + 10;

	printf("3번째 요소 입력 받기 : ");
	scanf("%d", ary+ 2);
	for (int i = 0; i < 3; i++)
		printf("%5d", *(ary + i));
	return (0);
}