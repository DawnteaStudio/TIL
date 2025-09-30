#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp (string &a, string &b)
{
	int len_a = a.length();
	int len_b = b.length();

	return len_a < len_b;
}

int main() {
	fast;
	int n;
	int id = 1;

	while (true) {
		cin >> n;
		if (n == 0)
			break;

		vector<string> vec(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		sort(vec.begin(), vec.end(), cmp);
		vector<string> ans(n);
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0)
				ans[i / 2] = vec[i];
			else
				ans[n - (i / 2) - 1] = vec[i];
		}
		cout << "SET " << id++ << '\n';
		for (int i = 0; i < n; i++)
			cout << ans[i] << '\n';
	}
}
