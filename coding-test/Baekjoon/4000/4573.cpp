#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void) {
    fast;
	int t = 0, res, n, d, p;
    while (true) {
		cin >> n;

		double cnt = 99999999;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			cin >> d >> p;
			if (cnt > p / (M_PI * (d / 2.) * (d / 2.))) {
				cnt = p / (M_PI * (d / 2.) * (d / 2.));
				res = d;
			}
		}
		t++;
		cout << "Menu " << t << ": " << res << '\n';
	}
}