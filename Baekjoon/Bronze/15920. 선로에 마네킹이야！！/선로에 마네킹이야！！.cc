#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, res = 0, pos = 0;
	bool is_pull = false;
	bool is_drift = false;
	string str;

	cin >> n >> str;
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] == 'W') {
			pos++;
			if (pos == 2) {
				if (is_drift)
					res = 6;
				else if (is_pull)
					res = 1;
				else
					res = 5;
				break;
			}
		}
		else {
			is_pull = is_pull != true;
			if (pos == 1)
				is_drift = true;
		}
	}
	cout << res;
}