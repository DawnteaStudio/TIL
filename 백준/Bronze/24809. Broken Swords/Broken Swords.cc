#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int tb = 0, lr = 0, res = 0;
	string input;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < 4; j++)
		{
			if (input[j] == '0')
			{
				if (j < 2)
					tb++;
				else
					lr++;
			}
		}
	}
	res = tb > lr ? lr : tb;
	res /= 2;
	tb -= res * 2;
	lr -= res * 2;
	cout << res << " " << tb << " " << lr;
}
