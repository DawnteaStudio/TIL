#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long mat(int n)
{
	long long res = 0;
	for (int i = 1; i <= n; i++)
		res += i;
	return res;
}

int main()
{
	fast;
	long long res = 1;
	int n, m;
	cin >> n >> m;

	for (int i = n; i <= m; i++) {
		res *= mat(i);
		res %= 14579;
	}
	cout << res;
}
