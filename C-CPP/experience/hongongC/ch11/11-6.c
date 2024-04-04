#include <stdio.h>

void	my_gets(char *str, int size)
{
	char ch;
	int i;

	for (i = 0; i < size; i++)
	{
		ch = getchar();
		if (ch != '\n')
			str[i] = ch;
		else
			break;
	}
	str[i] = 0;
}

int main(void)
{
	char str[7];

	my_gets(str, sizeof(str));
	printf("input line : %s\n", str);

	return (0);
}