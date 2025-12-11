#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int total, k, s;
		cin >> total >> k >> s;

		cout << "Case #" << i << ": ";
		if (total + k < total + (2 * (k - s)))
			cout << total + k << '\n';
		else
			cout << total + (2 * (k - s)) << '\n';
	}
}
