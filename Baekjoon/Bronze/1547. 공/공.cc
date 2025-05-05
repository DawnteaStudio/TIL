#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;
	int res = 1;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a == res || b == res)
		{
			if (a == res)
				res = b;
			else
				res = a;
		}
	}
	cout << res;
}