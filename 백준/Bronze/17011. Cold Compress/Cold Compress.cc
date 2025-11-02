#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		int len = str.length();

		int tmp = 1;
		char bef = str[0];
		for (int j = 1; j < len; j++) {
			if (str[j] == bef) {
				tmp++;
			}
			else {
				cout << tmp <<  " " << bef << " ";
				tmp = 1;
			}
			bef = str[j];
		}
		cout << tmp << " " << bef << " " << '\n';
	}
}
