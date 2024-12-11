#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	long long l, r, b, k, res;
	cin >> l >> r >> b >> k;

	if (l <= b)
		res = b * k;
	else
	{
		int tmp = b;
		while (tmp < l)
			tmp += b;
		res = tmp * k;
	}
	cout << res;
}
