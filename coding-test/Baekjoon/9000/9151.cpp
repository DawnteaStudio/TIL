#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int cal_one(int n)
{
	return n * n * n;
}

int cal_two(int n)
{
	return (n * (n + 1) * (n + 2)) / 6;
}

int main() {
    fast;
	int n;
	while (true) {
		cin >> n;
		if (n == 0)
			break;

		int res = 200000;
		int ans;
		for (int i = 54; i >= 0; i--) {
			for (int j = 96; j >= 0; j--) {
				int val = cal_one(i) + cal_two(j);

				if (val > n)
					continue;
				else {
					if (res > n - val) {
						ans = val;
						res = n - val;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}
