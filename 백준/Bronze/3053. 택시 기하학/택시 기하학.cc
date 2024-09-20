#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	double l;
	cin >> l;

	cout.precision(6);
	cout << fixed;
	cout << l * l * M_PI << '\n';
	cout << l * l * 2.;
}
