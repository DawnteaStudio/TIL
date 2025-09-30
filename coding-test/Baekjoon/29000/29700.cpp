#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m, k;

int res;

int main() {
	fast;
	cin >> n >> m >> k;

	vector<string> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m - k; j++) {
			if (arr[i][j] == '1')
				continue;
			for (int t = j; t < j + k; t++) {
				if (arr[i][t] == '1') {
					j = t;
					break;
				}
				if (t == j + k - 1)
					res++;
			}
		}
	}
	cout << res;
}
