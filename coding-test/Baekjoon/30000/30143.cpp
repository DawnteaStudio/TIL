#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void) {
	fast;

	int t;
	cin >> t;

	int n, a, d;
	for (int i = 0; i < t; i++) {
		cin >> n >> a >> d;

		cout << n * a + (n * (n - 1) * d) / 2 << '\n';
	}
}
