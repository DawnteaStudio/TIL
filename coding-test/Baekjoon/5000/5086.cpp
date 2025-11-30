#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int a, b;

	while (true) {
		cin >> a >> b;
		if (a == 0)
			break;
		if (a % b == 0)
			cout << "multiple\n";
		else if (b % a == 0)
			cout << "factor\n";
		else
			cout << "neither\n";
	}
}
