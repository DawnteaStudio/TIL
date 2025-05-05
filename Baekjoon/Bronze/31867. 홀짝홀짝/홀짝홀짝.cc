#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	string input;
	cin >> n >> input;

	int odd = 0, even = 0;
	for (int i = 0; i < n; i++)
	{
		if ((int)input[i] % 2 == 0)
			even++;
		else
			odd++;
	}

	if (even > odd)
		cout << 0;
	else if (even < odd)
		cout << 1;
	else
		cout << -1;
}