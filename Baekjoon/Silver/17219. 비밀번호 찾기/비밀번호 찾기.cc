#include <iostream>
#include <string>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m;
	string address, pwd;
	map<string ,string> memo;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> address >> pwd;
		memo.insert({address, pwd});
	}
	for (int i = 0; i < m; i++)
	{
		cin >> address;
		cout << memo.find(address)->second << '\n';
	}
}