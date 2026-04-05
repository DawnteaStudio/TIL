#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n, len;
	cin >> n;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		len = str.length();
		if (len % 2)
			cout << "Do-it\n";
		else {
			if (str[len / 2] == str[len / 2 - 1])
				cout << "Do-it\n";
			else
				cout << "Do-it-Not\n";
		}
	}
}
