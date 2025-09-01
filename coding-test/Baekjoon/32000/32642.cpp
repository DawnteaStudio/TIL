#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int rage;

int main() {
    fast;
	long long res = 0;
	int n, w;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> w;
		if (w)
			rage++;
		else
			rage--;
		res += rage;
	}
	cout << res;
}
