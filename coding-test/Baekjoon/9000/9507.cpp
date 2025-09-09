#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long arr[70];

long long solve(int tmp) {
	if (arr[tmp]) {
		return arr[tmp];
	}
	arr[tmp] = solve(tmp - 1) + solve(tmp - 2) + solve(tmp - 3) + solve(tmp - 4);
	return arr[tmp];
}

int main() {
	fast;
	int n, tmp;

	cin >> n;
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cout << solve(tmp) << '\n';
	}
}
