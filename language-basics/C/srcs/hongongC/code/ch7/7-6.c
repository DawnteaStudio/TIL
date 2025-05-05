#include <stdio.h>

void	fruit(int cnt);

int main(void)
{
	fruit(0);
	return (0);
}

void	fruit(int cnt)
{
	printf("apple\n");
	if (cnt == 2)
		return ;
	fruit(cnt + 1);
}