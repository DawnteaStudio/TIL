#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	cin >> str;

	int len, under = 0, colon = 0;
	len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == '_')
			under++;
		else if (str[i] == ':')
			colon++;
	}
	cout << len + colon + under * 5;
}