#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	int n, res, tmp;
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		res = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			if (res + tmp <= 300)
				res += tmp;
		}
		cout << res << '\n';
	}
}