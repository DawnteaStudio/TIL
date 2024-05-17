#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;

int main()
{
	fast;

	ll d, n, m, k, small, big, res;
	cin >> d >> n >> m >> k;
	res = k;
	n %= d;
	m %= d;
	k %= d;
	res -= k;
	if (n > m)
	{
		small = (d - n);
		big = (d - m);
	}
	else
	{
		small = (d - m);
		big = (d - n);
	}

	if (k < small && (d + k) >= (small + big))
	{
		res -= d;
		k += d;
	}
	if (k >= small)
		k -= small;
	if (k >= big)
		k -= big;
	cout << res + k;
}