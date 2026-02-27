#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int t;
	string str, a, b;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> str;
		a = "";
		b = "";

		int len = str.length();
		while (len > 2) {
			if (str.substr(0, len / 2) != str.substr(len / 2))
				break;
			str = str.substr(0, len / 2);
			len = str.length();
		}

		if (str.length() % 2)
			str += str;
		len = str.length();

		for (int j = 0; j < len; j++) {
			if (j % 2 == 0)
				a += str[j];
			else
				b += str[j];
		}
		cout << a << '\n' << b << '\n';
	}
}
