#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, n;
	cin >> t >> n;

	int res = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		res += x;
	}
	if (res < t)
		cout << "Padaeng_i Cry";
	else
		cout << "Padaeng_i Happy";
}