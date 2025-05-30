#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m;
	cin >> n >> m;

	if (n > 60) {
		if (n > 60 + m) {
			cout << (60 + m) * 1500 + (n - 60 - m) * 3000;
		}
		else {
			cout << n * 1500;
		}
	}
	else {
		cout << n * 1500;
	}
}
