#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int get_t(string &t)
{
	int res = 0, m = 0;
	res += (t[0] - '0') * 60;

	for (int i = 2; i <= 3; i++)
		m = m * 10 + t[i] - '0';
	return res + m;
}

int main()
{
	fast;

	int n, time, bef, befbef;
	int ans = 2;
	string t;
	cin >> n;

	if (n == 1)
		cout << 2;
	else if (n == 2) {
		cin >> t;
		int s = get_t(t);
		cin >> t;
		int e = get_t(t);
		if (e - s <= 10)
			cout << 1;
		else
			cout << 2;
	}
	else {
		cin >> t;
		befbef = get_t(t);
		cin >> t;
		bef = get_t(t);
		if (bef - befbef <= 10)
			ans = 1;
		for (int i = 2; i < n; i++) {
			cin >> t;
			time = get_t(t);
			if (time - befbef <= 10)
				ans = 0;
			if (time - bef <= 10 && ans > 1)
				ans = 1;
			befbef = bef;
			bef = time;
		}
		cout << ans;
	}
}
