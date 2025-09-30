#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n;
	cin >> n;

	double tmp;
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cout << "$" << tmp * 4 / 5 << '\n';
	}
}
