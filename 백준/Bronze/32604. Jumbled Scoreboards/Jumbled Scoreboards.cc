#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, a, b, aa, bb;
	cin >> n;
	bool flag = true;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cin >> a >> b;
		else
		{
			cin >> aa >> bb;
			if (a > aa || b > bb)
			{
				flag = false;
				break;
			}
			a = aa;
			b = bb;
		}
	}
	if (flag)
		cout << "yes";
	else
		cout << "no";
}
