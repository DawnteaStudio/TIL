#include <iostream>
#include <string>
#include <cctype>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int j, n; cin >> j >> n;
	cin.ignore();
	cin.clear();

	string str;
	int cnt = 0;
	for (int i=0; i<n; i++) {
		getline(cin, str);
		int tmp = 0;
		for (int k=0; k<(int)str.size(); k++) {
			if (isupper(str[k])) tmp += 4;
			else if (islower(str[k]) || (str[k] >= '0' && str[k] <= '9')) tmp += 2;
			else tmp += 1;
		}
		if (tmp <= j) cnt++;
	}
	cout << cnt;
	return (0);
}