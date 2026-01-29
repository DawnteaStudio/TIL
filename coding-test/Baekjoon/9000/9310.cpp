// Arithmetic and Geometric Sums
#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int cal_case1(int n, int a1, int diff) {
	return n * (2 * a1 + (n - 1) * diff) / 2;
}

int cal_case2(int n, int a1, int r) {
	return a1 * ((int)pow(r, n) - 1) / (r - 1);
}

int main()
{
	fast;
	while (true) {
		int n; cin >> n;
		if (n == 0) break ;

		int a[3], result;
		for (int i=0; i<3; i++) cin >> a[i];
		if (a[1] - a[0] == a[2] - a[1]) result = cal_case1(n, a[0], a[1] - a[0]);
		else result = cal_case2(n, a[0], a[1] / a[0]);
		cout << result << '\n';
	}
	return (0);
}