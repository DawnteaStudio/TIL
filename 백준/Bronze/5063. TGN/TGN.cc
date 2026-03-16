#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int r, e, c;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> r >> e >> c;
		if (r > e - c)
			cout << "do not advertise\n";
		else if (r == e - c)
			cout << "does not matter\n";
		else
			cout << "advertise\n";
	}
}
