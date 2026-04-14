#include <iostream>
#include <iomanip>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
    double x, y;
	cin >> x >> y;

	int n;
	cin >> n;

	cout << fixed;
	cout << setprecision(2);
	double res = 1000 * x / y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		double tmp = 1000 * x / y;
		if (tmp < res)
			res = tmp;
	}
	cout << res;
}
