#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, n, m;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		cin >> n >> m;
		cout << m - n + 1 << '\n';
	}
}
