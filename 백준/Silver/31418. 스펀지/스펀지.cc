#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	long long w, h, k, t;
	cin >> w >> h >> k >> t;
	long long res = 1;

	long long x, y;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;

		long long tmp1 = (min(w, x + t) - max((long long)1, x - t) + 1);
		long long tmp2 = (min(h, y + t) - max((long long)1, y - t) + 1);
		res = res * (tmp1 * tmp2 % 998244353) % 998244353;
	}
	cout << res;
}