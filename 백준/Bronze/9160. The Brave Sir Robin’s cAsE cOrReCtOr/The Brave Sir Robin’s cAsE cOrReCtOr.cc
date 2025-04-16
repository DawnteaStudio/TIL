#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	bool flag = false;
	string s, tmp;
	int len;
	while (getline(cin, tmp)) {
		s += tmp;
		s += '\n';
	}
	len = s.length();

	for (int i = 0; i < len; i++) {
		if (s[i] == ' ' || s[i] == '(' || s[i] == ')' || s[i] == '\n')
			cout << s[i];
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			if (flag) {
				cout << s[i];
				flag = false;
			}
			else
				cout << char(s[i] + 32);
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			if (flag) {
				cout << char(s[i] - 32);
				flag = false;
			}
			else
				cout << s[i];
		}
		else if (s[i] == '.' || s[i] == '!' || s[i] == '?') {
			cout << s[i];
			flag = true;
		}
		else {
			cout << s[i];
			if (flag)
				flag = false;
		}
	}
}
