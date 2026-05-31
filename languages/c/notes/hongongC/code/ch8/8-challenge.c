#include <stdio.h>

int main(void)
{
	char	str[100];
	char	str2[100];
	int	cnt = 0;

	printf("문장 입력 : ");
	gets(str);
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str2[i] = str[i] - 'A' + 'a';
			cnt++;
		}
		else
			str2[i] = str[i];
		i++;
	}
	str2[i] = 0;
	printf("바뀐 문장 : %s\n", str2);
	printf("바뀐 문자 수 : %d\n", cnt);
}