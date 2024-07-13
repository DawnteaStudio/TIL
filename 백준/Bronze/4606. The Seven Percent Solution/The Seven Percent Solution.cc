#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str, res;
	while (true)
	{
		getline(cin, str);
		if (str == "#")
			break;
		res = "";
		for (int i = 0; i < str.length(); i++)
		{
			switch (str[i])
			{
				case ' ':
					res += "%20";
					break;
				case '!':
					res += "%21";
					break;
				case '$':
					res += "%24";
					break;
				case '%':
					res += "%25";
					break;
				case '(':
					res += "%28";
					break;
				case ')':
					res += "%29";
					break;
				case '*':
					res += "%2a";
					break;
				default:
					res += str[i];
					break;
			}
		}
		cout << res << '\n';
	}
}
