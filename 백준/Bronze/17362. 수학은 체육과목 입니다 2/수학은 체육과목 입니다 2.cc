#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	
	int n;
	cin >> n;

	n %= 8;
	if (n == 0)
		n = 8;
	if (n > 5)
		n -= (n - 5) * 2;
	cout << n;
	return (0);
}