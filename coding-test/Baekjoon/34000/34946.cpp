#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a + b <= d && c <= d)
		cout << "~.~";
	else if (a + b <= d)
		cout << "Shuttle";
	else if (c <= d)
		cout << "Walk";
	else
		cout << "T.T";
}
