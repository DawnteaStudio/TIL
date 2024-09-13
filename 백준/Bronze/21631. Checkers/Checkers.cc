#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	long long a, b, res;
	cin >> a >> b;

	if (a >= b)
		cout << b;
	else
		cout << a + 1;
}
