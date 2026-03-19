#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n;
	cin >> n;
	cin.ignore();
	string str;

	int tmp;
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		tmp = 0;
		int len = str.length();

		for (int j = 0; j < len; j++) {
			if (str[j] >= 'A' && str[j] <= 'Z')
				tmp += str[j] - 'A' + 1;
		}
		if (tmp == 100)
			cout << "PERFECT LIFE\n";
		else
			cout << tmp << '\n';
	}
}
