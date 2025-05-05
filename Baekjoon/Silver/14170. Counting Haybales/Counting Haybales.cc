#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, q;
	int start, end;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (int j = 0; j < q; j++) {
		cin >> start >> end;
		int l = lower_bound(a.begin(), a.end(), start) - a.begin();
		int r = upper_bound(a.begin(), a.end(), end) - a.begin();
		cout << r - l << '\n';
	}
}
