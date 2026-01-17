#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n, c, t, res = 0;
	cin >> n >> c;
	vector<int> vec(c + 1, 0);

	for (int i = 0; i < n; i++) {
		cin >> t;

		for (int j = t; j <= c; j += t) {
			if (vec[j] == 0) {
				res++;
				vec[j]++;
			}
		}
	}
	cout << res;
}
