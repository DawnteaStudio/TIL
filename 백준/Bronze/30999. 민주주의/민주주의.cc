#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	int q, human, res = 0;

	cin >> q >> human;
	for (int i = 0; i < q; i++) {
		string s;
		cin	>> s;
		int count = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'O') {
				count++;
			}
		}
		if (count > human / 2)
			res++;
	}
	cout << res;
}
