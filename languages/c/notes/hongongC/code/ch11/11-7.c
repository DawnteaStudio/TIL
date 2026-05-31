#include <stdio.h>

int main(void)
{
	int num, grade;

	printf("input ID : ");
	scanf("%d", &num);
	while (getchar() != '\n');
	printf("input score : ");
	grade = getchar();
	printf("ID : %d, score : %c\n", num, grade);

	return (0);
}