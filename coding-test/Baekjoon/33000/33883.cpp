#include <iostream>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool f(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

int main() {
	fast;

	string tmp;
	cin >> tmp;

	int res = -1;
	int len = tmp.length();
	if (f(tmp[len - 1])) {
		bool flag = false;
		for (int i = len - 1; i >= 0; i--) {
			if (f(tmp[i])) {
				if (flag == false)
					flag = true;
				else {
					res = i + 1;
					break;
				}
			}
		}
	}
	else if (tmp[len - 1] != 'n' && tmp[len - 1] != 's') {
		for (int i = len - 1; i >= 0; i--) {
			if (f(tmp[i])) {
				res = i + 1;
				break;
			}
		}
	}
	else {
		bool flag = false;
		for (int i = len - 1; i >= 0; i--) {
			if (f(tmp[i])) {
				if (flag == false)
					flag = true;
				else {
					res = i + 1;
					break;
				}
			}
		}
	}
	cout << res;
}
