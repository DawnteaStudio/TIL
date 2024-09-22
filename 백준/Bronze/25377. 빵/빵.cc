#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, a, b, res = -1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a > b)
			continue;
		if (res == -1)
			res = b;
		else
		{
			if (res > b)
				res = b;
		}
	}
	cout << res;
}
