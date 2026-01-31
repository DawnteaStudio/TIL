#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	string str;
	int cnt = 0;
	int arr[26] = {0, };

	while (true) {
		getline(cin, str);
		cnt = 0;
		for (int i = 0; i < 26; i++)
			arr[i] = 0;
		if (str == "*")
			break;
		int len = str.length();

		for (int i = 0; i < len; i++) {
			if (str[i] == ' ')
				continue;
			if (arr[str[i] - 'a'] == 0) {
				arr[str[i] - 'a']++;
				cnt++;
			}
		}
		if (cnt == 26)
			cout << "Y\n";
		else
			cout << "N\n";
	}
}
