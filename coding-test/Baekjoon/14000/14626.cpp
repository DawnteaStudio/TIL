#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	
	string input;
	cin >> input;

	int check = input[12] - '0';
	int res = 0;
	int hidden;

	for (int i = 0; i < 12; i++) {
		if (input[i] != '*') {
			if (i % 2 == 0)
				res += input[i] - '0';
			else
				res += 3 * (input[i] - '0');
		}
		else {
			if (i % 2)
				hidden = 3;
			else
				hidden = 1;
		}
	}
	int now = res % 10;

	for (int i = 0; i < 10; i++) {
		if ((now + check) % 10 + (hidden * i % 10) == 10 || (now + check) % 10 + (hidden * i % 10) == 0) {
			cout << i;
			break;
		}
	}
}
