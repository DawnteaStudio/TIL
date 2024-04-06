#include <iostream>
#include <string>
#include <set>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	string str, tmp;
	cin >> str;
	set<string> sub;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 1; j <= str.length(); j++)
		{
			tmp = str.substr(i, j);
			sub.insert(tmp);
		}
	}
	cout << sub.size();
}
