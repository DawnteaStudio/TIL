#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
	fast;
	int n, win = 0;

	cin >> n;
	int a, d, g;
	for (int i = 0; i < n; i++) {
		cin >> a >> d >> g;
		int tmp = a * (d + g);
		if (a == d + g)
			tmp *= 2;
		if (tmp > win) {
			win = tmp;
		}
	}
	cout << win;
}
