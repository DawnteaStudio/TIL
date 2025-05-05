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
	long long w_size, h_size;
	for (int i = 0; i < k; i++) {
		w_size = 1;
		h_size = 1;
		cin >> x >> y;
		if (x + t > w)
			w_size += w - x;
		else
			w_size += t;
		if (x - t < 1)
			w_size += x - 1;
		else
			w_size += t;
		if (y + t > h)
			h_size += h - y;
		else
			h_size += t;
		if (y - t < 1)
			h_size += y - 1;
		else
			h_size += t;
		res = res * ((w_size * h_size) % 998244353) % 998244353;
	}
	cout << res;
}
