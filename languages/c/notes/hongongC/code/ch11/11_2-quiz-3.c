#include <stdio.h>

int main(void)
{
	int ch;
	int cnt = 0;
	ch = getchar();

	while(ch != '\n')
	{
		if (ch >= 'a' && ch <= 'z')
			cnt++;
		ch = getchar();
	}
	printf("소문자 갯수 : %d\n", cnt);
	return (0);
}