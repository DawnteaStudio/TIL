#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b;
	cin >> a >> b;

	if (a < 2)
		cout << "Before\n";
	else if (a == 2)
	{
		if (b < 18)
			cout << "Before\n";
		else if (b == 18)
			cout << "Special\n";
		else
			cout << "After\n";
	}
	else
		cout << "After\n";
}