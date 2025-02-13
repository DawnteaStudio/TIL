#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, l, k, cnt = 0;
	cin >> n >> l >> k;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		if (vec[i] <= l) {
			cnt++;
			l += k;
		}
		else
			break;
	}
	cout << cnt;
}