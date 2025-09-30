#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int len, cnt;
string str;
int res = 101;

void solve(int idx, int acc, int c)
{
	if (c == cnt)
		return;
	for (int i = idx; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (str[i] == str[j] && str[i] != 'X') {
				solve(j + 1, acc + (i - idx), c + 1);
				if (res > acc + (i - idx) + (len - j - 1))
					res = acc + (i - idx) + (len - j - 1);
			}
		}
	}
}

int main() {
	fast;
    
	cin >> len >> cnt;
	res = len;
	cin >> str;

	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (str[i] == str[j] && str[i] != 'X') {
				solve(j + 1, i, 1);
				if (res > i + (len - j - 1))
					res = i + (len - j - 1);
			}
		}
	}

	cout << res;
}
