#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res;

int main() {
	fast;
    
	string str;
	cin >> str;
	int len = str.length();

	for (int i = 0; i < len - 4; i++) {
		if (str[i] == ')')
			continue;
		if (str[i + 1] == ')')
			continue;
		for (int k = i + 2; k < len - 1; k++) {
			if (str[k] == ')' && str[k + 1] == ')')
				res++;
		}
	}
	cout << res;
}
