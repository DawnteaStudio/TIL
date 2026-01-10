#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		if (a + b == 13)
			cout << "Never speak again.\n";
		else if (a > b)
			cout << "To the convention.\n";
		else if (a < b)
			cout << "Left beehind.\n";
		else
			cout << "Undecided.\n";
	}
}