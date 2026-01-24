#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int cal(string &str)
{
	int tmp = 0;

	int len = str.length();
	tmp += str[len - 1] - '0';
	tmp += (str[len - 2] - '0') * 10;

	return tmp;
}

int main() {
    fast;
	int n, res = 0;
	cin >> n;
	int now;

	string str;
	cin >> str;
	now = cal(str);

	for (int i = 0; i < n; i++) {
		cin >> str;
		now += cal(str);
		now %= 100;
		if (now != 0)
			res++;
	}
	cout << res;
}
