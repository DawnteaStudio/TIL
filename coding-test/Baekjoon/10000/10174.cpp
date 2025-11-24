// 팰린드롬
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

char normalize(char ch) {
	if (ch >= 'a' && ch <= 'z') return ch - ('a' - 'A');
	return ch;
}

bool check(string &str) {
	int size = (int)str.size();
	for (int i=0; i<=size/2; i++) {
		if (normalize(str[i]) != normalize(str[size - i - 1]))
			return false;
	}
	return true;
}

int main()
{
	fast;
	int t; cin >> t;
	cin.ignore();
	cin.clear();
	string str;
	for (int i=0; i<t; i++) {
		getline(cin, str);
		if (check(str)) cout << "Yes\n";
		else cout << "No\n";
	}
	return (0);
}