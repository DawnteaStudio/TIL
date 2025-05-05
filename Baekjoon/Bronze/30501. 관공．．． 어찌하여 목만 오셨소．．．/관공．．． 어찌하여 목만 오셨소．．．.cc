#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str.find('S') != string::npos)
		{
			cout << str;
			break;
		}
	}
}
