#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int n;
	string s;
	cin >> n >> s;

	int len = s.length();
	char c = s[0];
	for (int i = 1; i < len; i++) {
		if (c != s[i]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
}
