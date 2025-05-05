#include <stdio.h>

int main(void)
{
	char str[80] = "applejam";

	printf("init line : %s\n", str);
	printf("input new line : ");
	scanf("%s", str);
	printf("new line : %s\n", str);

	return (0);
}