#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, a, tmp, res = 0;
	cin >> n >> a;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		res += tmp / a;
	}
	cout << res;
}