#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, res = -1, sum;
	cin >> n;
	vector<int> vec(2 * n);
	for (int i = 0; i < 2 * n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++)
	{
		sum = vec[i] + vec[2 * n - i - 1];
		if (res == -1 || sum < res)
			res = sum;
	}
	cout << res;
}
