#include <iostream>
#include <string>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int	get_num(string str)
{
	int n = 0;
	int	password;

	for (int i = str.length(); i > 0; i--)
	{
		if (str[str.length() - i] == '-')
			password = 0;
		else if (str[str.length() - i] == '\\')
			password = 1;
		else if (str[str.length() - i] == '(')
			password = 2;
		else if (str[str.length() - i] == '@')
			password = 3;
		else if (str[str.length() - i] == '?')
			password = 4;
		else if (str[str.length() - i] == '>')
			password = 5;
		else if (str[str.length() - i] == '&')
			password = 6;
		else if (str[str.length() - i] == '%')
			password = 7;
		else if (str[str.length() - i] == '/')
			password = -1;
		n += (pow(8, i - 1) * password);
	}
	return (n);
}

int main()
{
	fast;
	string str = "";
	int	n;
	while (1)
	{
		cin >> str;
		if (str[0] == '#')
			break;
		n = get_num(str);
		cout << n << '\n';
	}
}
