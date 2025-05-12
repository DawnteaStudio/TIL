#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, res = -1;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 0; i < (n / 2); i++) {
		int tmp = v[i] + v[n - 1 - i];
		if (res == -1 || res > tmp)
			res = tmp;
	}
	cout << res;
}