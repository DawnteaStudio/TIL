#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	int x, y;
	cin >> x >> y;

	if (x > y)
		cout << x + y;
	else
		cout << y - x;
}
