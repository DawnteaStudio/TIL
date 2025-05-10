#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

#define MOD 1000000007
int main()
{
	fast;
	int n, x;
	long long res = 0;
	cin >> n >> x;
	vector<pair<int, int> > f(n + 1);
	for (int i = n; i >= 0; i--)
		cin >> f[i].first >> f[i].second;
	for (int i = n; i >= 0; i--) {
		res *= x;
		res += f[i].first;
		res %= MOD;
	}
	cout << res;
}