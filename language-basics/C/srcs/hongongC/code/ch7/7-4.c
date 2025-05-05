#include <stdio.h>

void	print_line(void);

int main(void)
{
	print_line();
	printf("something....\n");
	print_line();
}

void	print_line(void)
{
	for (int i = 0; i < 50; i++)
		printf("-");
	printf("\n");
}