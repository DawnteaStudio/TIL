#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
	fast;
	int n, cnt;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cnt;
		int res = 0;
		for (int j = 0; j < cnt; j++) {
			int tmp;
			cin >> tmp;
			res += tmp;
		}
		res *= 2;
		int b = 0, a;
		for (int j = 0; j < cnt; j++) {
			cin >> a;
			if (j == 0)
				res += a;
			else {
				if (a > b)
					res += (a - b);
				else
					res += (b - a);
			}
			b = a;
		}
		res += b;
		cout << res << '\n';
	}
}