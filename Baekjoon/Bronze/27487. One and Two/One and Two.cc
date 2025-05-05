#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
	fast;
	int t, l, r;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		int res = -1;
		l = 0, r = 0;
		cin >> n;
		vector<int> vec(n);
		for (int j = 0; j < n; j++) {
			cin >> vec[j];
			if (vec[j] == 2)
				r++;
		}
		for (int j = 0; j < n; j++) {
			if (vec[j] == 2) {
				l++;
				r--;
			}
			if (l == r) {
				res = j + 1;
				break;
			}
		}
		cout << res << '\n';
	}
}
