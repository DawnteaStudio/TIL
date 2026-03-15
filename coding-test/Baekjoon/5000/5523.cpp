#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n, a, b;
	int ra, rb;
	ra = 0, rb = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b)
			ra++;
		else if (a < b)
			rb++;
	}
	cout << ra << " " << rb;
}
