#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int x, n; cin >> x >> n;
	for (int i=1; i<=n; i++){
		if (x % 2 == 0)
			x = (int)((double)(x) / 2.0) ^ 6;
		else
			x = (2 * x) ^ 6;
	}
	cout << x;
	return (0);
}
