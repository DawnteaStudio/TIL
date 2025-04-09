#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main()
{
	fast;
	int n;
	cin >> n;

	cout << fixed;
	cout.precision(1);
	double a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		double res = abs(a - b);
		cout << res << '\n';
	}
}
