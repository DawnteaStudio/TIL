#include <iostream>
#include <string>
#include <set>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	string str, res;
	cin >> str;
	set<string> sub;
	for (int i = 0; i < str.length(); i++)
	{
        res = "";
		for (int j = i; j < str.length(); j++)
		{
		    res += str[j];
			sub.insert(res);
		}
	}
	cout << sub.size();
}
