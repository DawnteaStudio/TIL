#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int c, k, p;
	long long res = 0;
	cin >> c >> k >> p;

	for (int i = 1; i <= c; i++) {
		res += k * i + p * i * i;
	}
	cout << res;
}
