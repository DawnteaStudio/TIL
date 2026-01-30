#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n, res = 0, t, tmp;
	cin >> n;

	for (int i = 0; i < n; i++)  {
		res = 0;
		cin >> t;
		for (int j = 0; j < t; j++) {
			cin >> tmp;
			res += tmp;
		}
		cout << res << '\n';
	}
}
