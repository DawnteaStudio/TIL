#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int h, p;
	cout << fixed;
	cout.precision(2);

	while (true) {
		cin >> h >> p;
		if (cin.eof()) break ;
		cout << (double)h / p << '\n';
	}
}