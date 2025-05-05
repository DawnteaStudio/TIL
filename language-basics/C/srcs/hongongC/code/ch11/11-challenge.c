#include <stdio.h>

int main(void)
{
	int cnt = 0, tmp = 0, ch;
	ch = getchar();

	while(ch != -1)
	{
		if (ch == '\n')
		{
			if (tmp > cnt)
				cnt = tmp;
			tmp = 0;
		}
		else
			tmp++;
		ch = getchar();
	}
	printf("가장 긴 단어의 길이 : %d\n", cnt);
	return (0);
}