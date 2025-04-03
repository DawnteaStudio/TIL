#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
	fast;
	int c, tmp, res;
	int a, b;
	while (true) {
		cin >> c;
		res = -1;
		if (c == 0)
			break;
		for (int i = 1; i <= (int)sqrt(c); i++) {
			if (c % i == 0) {
				if (res == -1 || res > 2 * (i + c / i)) {
					res = 2 * (i + (c / i));
					a = i;
					b = c / i;
				}
			}
		}
		cout << "Minimum perimeter is " << res << " with dimensions " << a << " x " << b << '\n';
	}
}
