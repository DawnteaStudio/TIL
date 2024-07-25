#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int 	res;
bool	flag;

int	ft_pow(int i)
{
	int tmp = 1;
	while (i > 1)
	{
		tmp *= 10;
		i--;
	}
	return tmp;
}

int ft_len(int n)
{
	int tmp = 0;

	while (n > 0)
	{
		n /= 10;
		tmp++;
	}
	return tmp;
}

void	get_res(int n, int len, int tmp_res)
{
	int tmp = tmp_res;
	if (len == 0)
	{
		if (!flag && n == 0)
		{
			res = tmp_res;
			flag = true;
		}
		else
			return ;
	}
	int my_pow = ft_pow(len) + 1;
	for (int i = 0; i < 10; i++)
	{
		if (!flag)
		{
			tmp_res += (my_pow - 1) * i;
			if (my_pow * i > n)
				break;
			n -= my_pow * i;
			get_res(n, len - 1, tmp_res);
			n += my_pow * i;
			tmp_res = tmp;
		}
	}
}

int main() {
	fast;
	int n, len;
	cin >> n;

	len = ft_len(n);
	get_res(n, len, 0);
	cout << res << '\n';
}

