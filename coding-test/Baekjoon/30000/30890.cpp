#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int x, y;
	cin >> x >> y;

	int r = x * y;
	x = r / x;
	y = r / y;

	for (int i = 1; i <= r; i++) {
		if (i % x == 0 && i % y == 0)
			cout << 3;
		else if (i % x == 0)
			cout << 1;
		else if (i % y == 0)
			cout << 2;
	}
}
