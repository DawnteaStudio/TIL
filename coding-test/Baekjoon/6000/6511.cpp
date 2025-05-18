#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m, c, tmp;
	while (true) {
		tmp = 0;
		cin >> n >> m >> c;
		if (n == 0 && m == 0 && c == 0) break;
		if (c == 0) tmp = 1;
		int ans;

		ans = ((n - 6) / 2) * ((m - 6 - tmp) / 2);
		ans += ((n - 7) / 2) * ((m - 6 - c) / 2);
		cout << ans << '\n';
	}
}