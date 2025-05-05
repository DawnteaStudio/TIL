#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int tmp, res = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> tmp;
		if (tmp < 40)
			tmp = 40;
		res += tmp;
	}
	cout << res / 5;
}
