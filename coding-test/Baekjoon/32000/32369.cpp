#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int a = 1, b = 1;

	int d, good, bad;
	cin >> d >> good >> bad;
	for (int i = 0; i < d; i++) {
		a += good;
		b += bad;
		if (a < b)
			swap(a, b);
		else if (a == b)
			b--;
	}
	cout << a << " " << b;
}
