#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int n, input;
	cin >> n;
	int res = 0, now = 0;
	vector<bool> v(n + 1, false);

	for (int i = 0; i < 2 * n; i++) {
		cin >> input;
		if (v[input] == false) {
			now++;
			v[input] = true;
		}
		else
			now--;

		if (res < now)
			res = now;
	}
	cout << res;
}