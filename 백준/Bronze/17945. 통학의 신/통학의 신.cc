#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int a, b;
	int res1, res2;
	cin >> a >> b;

	res1 = ((-2 * a) + sqrt(4 * a * a - (4 * b))) / 2;
	res2 = ((-2 * a) - sqrt(4 * a * a - (4 * b))) / 2;
	if (res1 == res2)
		cout << res1;
	else
	{
		if (res1 > res2)
			cout << res2 << " " << res1;
		else
			cout << res1 << " " << res2;
	}
}
