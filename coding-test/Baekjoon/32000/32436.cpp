#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n;
	cin >> n;
	vector<vector<int> > v(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	}

	if (v[0][0] < v[0][1]) {
		if (v[0][0] < v[1][0])
			cout << 0;
		else
			cout << 3;
	}
	else {
		if (v[0][0] < v[1][0])
			cout << 1;
		else
			cout << 2;
	}
}