#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, res, input;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> input;
		res = 1;
		while (input)
		{
			res *= 2;
			input--;
		}
		cout << res - 1 << '\n';
	}
}
