#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int solve(int num)
{
	int c = sqrt(num);
	int ans = 0;
	for (int i = 1; i <= c; i++) {
		if (num % i == 0) {
			int j = num / i;
			if (i == j) ans++;
			else ans += 2;
		}
	}
	return ans;
}

int main()
{
	fast;
	int n, m;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		int x, y = 0;
		for (int i = n; i <= m; i++) {
			int ans = solve(i);
			if (ans >= y) {
				x = i;
				y = ans;
			}
		}
		cout << x << " " << y << endl;
	}
}