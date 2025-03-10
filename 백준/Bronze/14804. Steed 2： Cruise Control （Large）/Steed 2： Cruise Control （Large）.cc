#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, d, n, tmp_d, tmp_n;
	double res = 0, tmp;
	cin >> t;

	cout << fixed;
	cout.precision(6);
	for (int i = 1; i <= t; i++) {
		cin >> d >> n;
		res = 0;
		for (int j = 0; j < n; j++) {
			cin >> tmp_d >> tmp_n;
			tmp = static_cast<double>((d - tmp_d)) / tmp_n;

			if (res == 0)
				res = d / tmp;
			else if (res > d / tmp)
				res = d / tmp;
		}
		cout << "Case #" << i << ": " << res << '\n';
	}
}