#include <iostream>
#include <vector>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, cnt = 0;
	long long res;
	cin >> n;

	map<long long, int> m;
	for (int i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;

		if (m.find(tmp) == m.end())
			m[tmp] = 1;
		else
			m[tmp]++;
		if (m[tmp] > cnt) {
			res = tmp;
			cnt = m[tmp];
		}
		else if (m[tmp] == cnt) {
			if (res > tmp)
				res = tmp;
		}
	}
	cout << res;
}
