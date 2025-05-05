#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	string str;
	cin >> n;
	getline(cin, str);
	for (int i = 1; i <= n; i++)
	{
		getline(cin, str);
		cout << i << ". " << str << '\n';
	}
}