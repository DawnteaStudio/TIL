#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n, c, l;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> c;
		cout << 2 * c - l << " " << l - c << '\n';
	}
    return 0;
}
