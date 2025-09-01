#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
    int q;
	cin >> q;

	int ta, tb, va, vb;
	int res;
	for (int i = 0; i < q; i++) {
		res = 0;
		cin >> ta >> tb >> va >> vb;
		int remove_a = tb * vb / ta;
		int rest_a = tb * vb % ta;

		res += tb * vb;

		if (va > remove_a) {
			va -= remove_a;
			res += ta * (va / 2);
			if (va % 2)
				res += ta - rest_a;
		}
		cout << res << '\n';
	}
}
