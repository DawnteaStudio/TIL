#include <iostream>
#include <map>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m, cnt = 0, res;
	cin >> n;
	map<string, bool> title;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		title[str] = false;
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> str;
		if (title.find(str) != title.end() && title[str] == false)
		{
			title[str] = true;
			cnt++;
		}
		if (cnt * 2 >= n)
		{
			res = i;
			break;
		}
	}
	cout << res;
}