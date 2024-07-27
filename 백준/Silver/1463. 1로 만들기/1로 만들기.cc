#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res = 1000000;

void	make_one(int n, int cnt, int calc)
{
	if (n == 1)
	{
		if (cnt < res)
			res = cnt;
	}
	else
	{
		if (cnt >= res)
			return ;
		if (calc == 0)
		{
			if (n % 3 == 0)
			{
				for (int i = 0; i < 3; i++)
					make_one(n / 3, cnt + 1, i);
			}
		}
		else if (calc == 1)
		{
			if (n % 2 == 0)
			{
				for (int i = 0; i < 3; i++)
					make_one(n / 2, cnt + 1, i);
			}
		}
		else if (calc == 2)
		{
			for (int i = 0; i < 3; i++)
				make_one(n - 1, cnt + 1, i);
		}
	}
}

int main()
{
	fast;
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++)
		make_one(n, 0, i);
	cout << res;
}
