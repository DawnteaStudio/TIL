#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool	cmp(long long a, long long b)
{
	return (a > b);
}

int main()
{
	fast;
	int	n, x;
	cin >> n >> x;

	int	tmp, res, before;
	cin >> res;
	for (int i = 1; i < n; i++)
	{
		cin >> tmp;
		if (i == 1)
		{
			res += tmp;
			before = tmp;
		}
		else
		{
			if (before + tmp < res)
				res = before + tmp;
			before = tmp;
		}
	}
	cout << res * x;
}