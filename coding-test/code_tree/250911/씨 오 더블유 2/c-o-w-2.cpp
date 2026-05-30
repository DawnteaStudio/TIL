#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res;

int main() {
	fast;
    
	int len;
	string str;
	cin >> len >> str;

	for (int i = 0; i < len - 2; i++) {
		if (str[i] != 'C')
			continue;
		for (int j = i + 1; j < len - 1; j++) {
			if (str[j] != 'O')
				continue;
			for (int k = j + 1; k < len; k++) {
				if (str[k] == 'W')
					res++;
			}
		}
	}
	cout << res;
}
