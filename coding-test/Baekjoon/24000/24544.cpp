#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int n, res = 0, tmp;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		res += vec[i];
	}
	cout << res << '\n';
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp)
			res -= vec[i];
	}
	cout << res;
}
