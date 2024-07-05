#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	while (true)
	{
		getline(cin, str);
		if (str == "END")
			break;
		for (int i = str.length() - 1; i >= 0; i --)
			cout << str[i];
		cout << '\n';
	}
}
