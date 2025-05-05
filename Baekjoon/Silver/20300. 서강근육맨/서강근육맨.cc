#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;
	vector<long long> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	long long res = -1, tmp;
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) {
			tmp = vec[i] + vec[n - 1 - i];
			if (res == -1)
				res = tmp;
			else if (res < tmp)
				res = tmp;
		}
	}
	else {
		for (int i = 0; i < n / 2; i++) {
			tmp = vec[i] + vec[n - 2 - i];
			if (res == -1)
				res = tmp;
			else if (res < tmp)
				res = tmp;
		}
	}
	cout << res;
}