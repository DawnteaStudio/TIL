#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[11];

int main() {
	fast;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		arr[m]++;
	}

	for (int i = 0; i <= 10; i++) {
		if (arr[i])
			cout << i << '\n';
	}
}
