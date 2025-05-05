#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b;
	cin >> a >> b;

	int x, k;
	cin >> k >> x;

	int res = 0;
	for (int i = a; i <= b; i++)
	{
		if (i - k > x)
			break;
		if (k + i >= 2 * k - x && k + i <= 2 * k + x)
			res++;
	}
	if (res)
		cout << res;
	else
		cout << "IMPOSSIBLE\n";
}