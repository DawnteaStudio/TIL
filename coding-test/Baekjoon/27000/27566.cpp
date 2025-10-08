#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int r, f;
	cin >> r >> f;
	int half = f / r;
	int mod = f % r;

	if (mod > (r / 2))
		half++;

	if (half % 2 == 0)
		cout << "up";
	else
		cout << "down";
}
