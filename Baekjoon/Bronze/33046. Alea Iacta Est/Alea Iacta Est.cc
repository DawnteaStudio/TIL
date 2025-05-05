#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int res = (a + b + c + d - 1) % 4;
	if (res)
		cout << res;
	else
		cout << 4;
}
