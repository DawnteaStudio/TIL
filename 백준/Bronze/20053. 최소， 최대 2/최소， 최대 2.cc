#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<int> vec(n);
		for(int j = 0; j < n; j++)
			cin >> vec[j];
		sort(vec.begin(), vec.end());
		cout << vec[0] << " " << vec[n - 1] << '\n';
	}
}
