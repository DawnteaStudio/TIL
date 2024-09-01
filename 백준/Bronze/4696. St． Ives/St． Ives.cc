#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	double n;
	cout << fixed;
	cout.precision(2);
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		cout << 1 + n + (n * n) + (n * n * n) + (n * n * n * n) << '\n';
	}
}
