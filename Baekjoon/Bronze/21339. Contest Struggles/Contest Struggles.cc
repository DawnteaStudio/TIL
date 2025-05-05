#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	double res;
	double n, k, d, s;
	cin >> n >> k >> d >> s;
	res = (n * d - k * s) / (n - k);
	cout << fixed;
	cout.precision(6);
	if (res > 100 || res < 0)
		cout << "impossible";
	else
		cout << res;
}
