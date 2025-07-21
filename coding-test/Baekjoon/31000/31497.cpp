#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    // fast;
    int n, ans;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < 2 * n; i++) {
		cout << "? " << v[i / 2] << endl;
		cout << flush;
		cin >> ans;
		if (ans == 1) {
			cout << "! " << v[i / 2];
			break;
		}
	}
}
