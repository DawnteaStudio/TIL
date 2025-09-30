#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int a, x, b, y; cin >> a >> x >> b >> y;
	int t; cin >> t;
	cout << a + (t > 30 ? (t - 30) * x : 0) * 21 << " " << b + (t > 45 ? (t - 45) * y : 0) * 21;
}
