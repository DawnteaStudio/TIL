#include <iostream>
#include <string>
#include <stack>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	string str;
	cin >> str;
	int res = 0, tmp = 1;
	stack<char> s;

	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[')
		{
			if (str[i] == '(')
				tmp *= 2;
			else
				tmp *= 3;
			s.push(str[i]);
		}
		else
		{
			if (str[i] == ')')
			{
				if (s.empty() || s.top() != '(')
				{
					res = 0;
					break;
				}
				if (str[i - 1] == '(')
					res += tmp;
				tmp /= 2;
			}
			else
			{
				if (s.empty() || s.top() != '[')
				{
					res = 0;
					break;
				}
				if (str[i - 1] == '[')
					res += tmp;
				tmp /= 3;
			}
			s.pop();
		}
	}
	if (!s.empty())
		res = 0;
	cout << res;
}