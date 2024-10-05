#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	cin >> str;
	int n;
	cin >> n;
	int start = 0;
	int len = str.length();
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		start += a;
	}
	if (start + b < len)
		str = str.substr(start, b);
	else
		str = str.substr(start);
	cout << str;
}