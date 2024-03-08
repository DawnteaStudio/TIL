#include <iostream>
#include <string>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string	str;
	char	tmp = '0';
	int		res = 0;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] - 1 != tmp)
			break;
		tmp++;
		res++;
	}
	if (res == str.length())
		cout << res;
	else
		cout << -1;
}
