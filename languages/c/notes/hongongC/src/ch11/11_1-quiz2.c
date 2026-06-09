#include <stdio.h>

int main(void)
{
	char ch;
	printf("input char : ");
	scanf("%c", &ch);
	printf("%c's ascii : %d\n", ch, (int)ch);
	return (0);
}