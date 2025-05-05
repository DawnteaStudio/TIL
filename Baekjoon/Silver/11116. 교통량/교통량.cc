#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m, res;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		res = 0;
		vector<int> left(m);
		vector<int> right(m);
		for (int j = 0; j < m; j++)
			cin >> left[j];
		for (int j = 0; j < m; j++)
			cin >> right[j];
		for (int j = 0; j < m; j += 2) {
			if (left[j] < right[j])
				res++;
		}
		cout << res << '\n';
	}
}