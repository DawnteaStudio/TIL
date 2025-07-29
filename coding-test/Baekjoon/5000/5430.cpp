#include <iostream>
#include <string>
#include <deque>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	
	int t, n, tmp;
	cin >> t;

	string ac, arr;
	bool r, err;
	for (int i = 0; i < t; i++) {
		r = false;
		err = false;
		cin >> ac >> n >> arr;

		arr = arr.substr(1, arr.length() - 2);
		int len = arr.length();
		tmp = n;
		deque<int> dq;

		int val = 0;
		for (int j = 0; j < len; j++) {
			if (arr[j] >= '0' && arr[j] <= '9')
				val = val * 10 + (arr[j] - '0');
			else {
				dq.push_back(val);
				val = 0;
			}
		}
		if (val)
			dq.push_back(val);

		len = ac.length();
		for (int j = 0; j < len; j++) {
			if (ac[j] == 'R')
				r = r == true ? false : true;
			else {
				if (tmp == 0) {
					err = true;
					cout << "error\n";
					break;
				}
				if (r)
					dq.pop_back();
				else
					dq.pop_front();
				tmp--;
			}
		}

		n = dq.size();
		if (!err) {
			cout << "[";
			if (r) {
				for (int j = n - 1; j >= 0; j--) {
					cout << dq[j];
					if (j)
						cout << ",";
				}
			}
			else {
				for (int j = 0; j < n; j++) {
					cout << dq[j];
					if (j != n - 1)
						cout << ",";
				}
			}
			cout << "]\n";
		}
	}
}
