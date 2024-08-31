#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, res = 0, input, tmp, low;
	cin >> n;

	cin >> tmp;
	low = tmp;
	for (int i = 1; i < n; i++)
	{
		cin >> input;
		if (tmp < input)
		{
			if (res < input - low)
				res = input - low;
		}
		else
			low = input;
		tmp = input;
	}
	cout << res;
}
