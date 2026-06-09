#include <stdio.h>

int main(void)
{
	int input, num = 2;
	int is_true;
	int cnt = 0;
	printf("2 이상의 정수를 입력하세요 : ");
	scanf("%d", &input);

	while (num <= input)
	{
		is_true = 1;
		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				is_true = 0;
				break;
			}
		}
		if (is_true)
		{
			printf("%5d ", num);
			cnt++;
			if (cnt == 5)
			{
				printf("\n");
				cnt = 0;
			}
		}
		num++;
	}
}