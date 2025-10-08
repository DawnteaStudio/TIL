#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	getline(cin, str);
	int len = str.length();

	for (int i = 0; i < 26; i++) {
		string tmp;
		for (int j = 0; j < len; j++) {
			if (str[j] >= 'A' && str[j] <= 'Z')
				tmp += (char)('A' + (str[j] - i + 26) % 26);
			else
				tmp += str[j];
		}
		if (tmp.find("LIVE") != string::npos && tmp.find("CHIPMUNKS") != string::npos) {
			cout << tmp;
			break;
		}
	}
}
