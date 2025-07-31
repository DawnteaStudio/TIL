#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;

int main() {
	fast;

	int n;
	cin >> n;

	int e;
	while (cin >> e) {
		if (n > e)
			n += e;
		else
			break;
	}
	cout << n;
}
