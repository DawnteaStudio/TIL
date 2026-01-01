#include <iostream>
#include <deque>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n, tmp;
	deque<int> dq;

	while (true) {
		cin >> n;
		dq.clear();
		int res = 0, now;

		if (n == 0)
			break;
		if (n <= 3) {
			for (int i = 0; i < n; i++) {
				cin >> tmp;
				res += tmp;
			}
			cout << res << '\n';
		}
		else {
			for (int i = 0; i < 3; i++) {
				cin >> tmp;
				res += tmp;
				dq.push_back(tmp);
			}
			now = res;
			for (int i = 3; i < n; i++) {
				cin >> tmp;
				now -= dq.front();
				now += tmp;
				dq.pop_front();
				dq.push_back(tmp);
				if (res < now)
					res = now;
			}
			cout << res << '\n';
		}
	}
}