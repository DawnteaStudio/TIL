#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int get_sum(int n)
{
	if (n % 2 == 0)
		return (1 + n) * (n / 2);
	return (1 + n) / 2 * n;
}

int main()
{
	fast;
	int n, k;
	cin >> n >> k;
	int sum = get_sum(k);
	if (sum > n)
		cout << -1;
	else if ((n - get_sum(k - 1)) % k == 0)
		cout << k - 1;
	else
	 cout << k;
}