#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void) {
	fast;
	string str;
	cin >> str;

	int last_0 = -1;
	int len = str.length();
	long long f = 1, b = 1;
	for (int i = 0; i < len; i++) {
		b *= str[i] - '0';
		if (str[i] == '0')
			last_0 = i;
	}
	for (int i = 0; i < len - 1; i++) {
		f *= str[i] - '0';
		if (str[i] != '0')
			b /= str[i] - '0';
		else if (last_0 == i) {
			b = 1;
			for (int j = i + 1; j < len; j++)
				b *= str[j] - '0';
		}
		else
			b = 0;
		if (f == b) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}
