#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, t, res = -1;
	cin >> n >> t;

	int s, e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		if (s + e > t)
			continue;
		if (s > res)
			res = s;
	}
	cout << res;
}
