#include <stdio.h>

void	input_nums(int *lotto_nums);
void	print_nums(int *lotto_nums);

int main(void)
{
	int lotto_nums[6];

	input_nums(lotto_nums);
	print_nums(lotto_nums);
	return (0);
}

void	input_nums(int *lotto_nums)
{
	int cnt = 0;
	int tmp, flag;

	while (cnt != 6)
	{
		printf("번호 입력 : ");
		scanf("%d", &tmp);
		flag = 0;
		for (int i = 0; i < cnt; i++)
		{
			if (tmp == lotto_nums[i])
			{
				printf("같은 번호가 있습니다.\n");
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			lotto_nums[cnt] = tmp;
			cnt++;
		}
	}
}

void	print_nums(int *lotto_nums)
{
	printf("로또 번호 : ");
	for (int i = 0; i <6; i++)
		printf("%d  ", lotto_nums[i]);
}