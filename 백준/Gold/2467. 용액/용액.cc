#include <iostream>
#include <vector>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	
	int s = 0, e = n - 1;
	int ans = 2000000001;
	int l, r;

	while (s < e) {
		int tmp = vec[s] + vec[e];
		if (abs(tmp) < abs(ans)) {
			ans = tmp;
			l = vec[s];
			r = vec[e];
		}
		if (tmp > 0)
			e--;
		else
			s++;
	}
	cout << l << " " << r;
}
