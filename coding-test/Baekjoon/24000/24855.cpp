#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	fast;

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	int res = 0;
	for (int i = 0; i < n / 2; i++)
		res += v[i];
	cout << res;
}