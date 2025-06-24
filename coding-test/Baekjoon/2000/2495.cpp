#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string s;
	for (int i = 0; i < 3; i++) {
		cin >> s;
		int res = 1, tmp = 1;
		int len = s.length();
		char start = s[0];
		for (int j = 1; j < len; j++) {
			if (s[j] == start) {
				tmp++;
			} else {
				start = s[j];
				res = max(res, tmp);
				tmp = 1;
			}
		}
		res = max(res, tmp);
		cout << res << '\n';
	}
}