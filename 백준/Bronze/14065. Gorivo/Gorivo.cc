#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	double x; cin >> x;

	cout.precision(6);
	cout << fixed;

	double tmp = x * 1609.344 / 3.785411784;
	cout << 100000.0 / tmp;
	return (0);
}