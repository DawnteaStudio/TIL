#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	string res;
	int a, b;
	cin >> a >> b;
	while (a || b) {
		int tmp = a % 10 + b % 10;
		a /= 10;
		b /= 10;
		res = to_string(tmp) + res;
	}
	cout << res;
}
