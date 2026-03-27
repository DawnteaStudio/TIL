#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	string a, op, b;
	cin >> a >> op >> b;

	int la, lb;
	la = a.length();
	lb = b.length();
	if (op == "*") {
		int zero = (la - 1) + (lb - 1);
		cout << 1;
		for (int i = 0; i < zero; i++)
			cout << 0;
	}
	else {
		if (la == lb) {
			cout << 2;
			for (int i = 1; i < la; i++)
				cout << 0;
		}
		else {
			int ml = max(la, lb);
			for (int i = ml; i > 0; i--) {
				if (i == la || i == lb)
					cout << 1;
				else
					cout << 0;
			}
		}
	}
}
