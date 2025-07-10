#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, n;
	cin >> t;
	string res;

	for (int i = 1; i <= t; i++) {
		cin >> n;
		if (n > 4500)
			res = ": Round 1\n";
		else if (n > 1000)
			res = ": Round 2\n";
		else if (n > 25)
			res = ": Round 3\n";
		else
			res = ": World Finals\n";
		cout << "Case #" << i << res;
	}
}
