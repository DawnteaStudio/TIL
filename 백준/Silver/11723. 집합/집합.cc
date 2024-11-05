#include <iostream>
#include <string>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, num;
	string cmd;
	map<int, int> res;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "all" || cmd == "empty")
		{
			if (cmd == "empty")
				res.clear();
			else
			{
				for (int j = 1; j <= 20; j++)
					res[j] = 1;
			}
		}
		else
		{
			cin >> num;
			if (cmd == "add")
				res[num] = 1;
			else if (cmd == "check")
			{
				if (res.find(num) != res.end())
					cout << 1 << '\n';
				else
					cout << 0 << '\n';
			}
			else if (cmd == "remove")
				res.erase(num);
			else
			{
				if (res.find(num) != res.end())
					res.erase(num);
				else
					res[num] = 1;
			}
		}
	}
}