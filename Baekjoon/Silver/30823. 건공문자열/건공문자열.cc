#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int len, pos;
	cin >> len >> pos;

	string str, res = "";
	cin >> str;

	res += str.substr(pos - 1);
	if ((len - pos + 1) % 2 != 0)
		reverse(str.begin(), str.begin() + pos - 1);
	res += str.substr(0, pos - 1);
	cout << res;
}
