#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int a, b, c;
	int res;

	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		if (2 * b == a + c)
			cout << "AP " << c + (c - b) << '\n';
		else
			cout << "GP " << c * c / b << '\n';
	}
}
