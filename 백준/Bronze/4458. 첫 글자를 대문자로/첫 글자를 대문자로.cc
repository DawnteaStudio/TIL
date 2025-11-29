#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n;
	cin >> n;
	cin.ignore();

	string str;
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		if (str[0] >= 'a')
			cout << (char)(str[0] - 'a' + 'A');
		else
			cout << str[0];
		cout << str.substr(1) << '\n';
	}
}
