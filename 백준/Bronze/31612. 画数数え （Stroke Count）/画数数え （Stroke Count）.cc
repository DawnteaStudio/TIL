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

	int res = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == 'j' || s[i] == 'i')
			res += 2;
		else
			res++;
	}
	cout << res;
}
