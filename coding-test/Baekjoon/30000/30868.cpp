#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
	fast;
	int t, cnt;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt / 5; j++) {
			cout << "++++ ";
		}
		for (int j = 0; j < cnt % 5; j++) {
			cout << "|";
		}
		cout << '\n';
	}
}