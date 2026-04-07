#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n, len, tmp;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		tmp = 0;
		len = str.length();

		for (int j = 0; j < len; j++) {
			char c = str[j];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				tmp++;
		}
		cout << "The number of vowels in " << str << " is " << tmp << ".\n";
	}
}
