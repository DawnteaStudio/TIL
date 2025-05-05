#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	cin >> str;

	int res = 0;
	int	len = str.length();
	for (int i = 0; i < len; i++)
	{
		res++;
		if (str[i] == 'n' && i + 1 < len && str[i + 1] == 'j')
			i++;
		else if (str[i] == 'l' && i + 1 < len && str[i + 1] == 'j')
			i++;
		else if (str[i] == 'c' && i + 1 < len && (str[i + 1] == '=' || str[i + 1] == '-'))
			i++;
		else if (str[i] == 's' && i + 1 < len && str[i + 1] == '=')
			i++;
		else if (str[i] == 'z' && i + 1 < len && str[i + 1] == '=')
			i++;
		else if (str[i] == 'd' && i + 1 < len && str[i + 1] == '-')
			i++;
		else if (str[i] == 'd' && i + 2 < len && str[i + 1] == 'z' && str[i + 2] == '=')
			i += 2;
	}
	cout << res;
}