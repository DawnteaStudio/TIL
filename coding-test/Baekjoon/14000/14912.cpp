#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;

	int n, t;
	cin >> n >> t;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int v = i;
		while (v > 0) {
			int ck = v % 10;
			v /= 10;
			if (ck == t)
				cnt++;
		}
	}
	cout << cnt;
}
