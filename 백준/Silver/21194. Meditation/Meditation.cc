#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(int &a, int &b)
{
	return a > b;
}

int main()
{
    fast;
	int n, t;
	cin >> n >> t;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	
	int res = 0;

	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < t; i++)
		res += vec[i];
	cout << res;
}
