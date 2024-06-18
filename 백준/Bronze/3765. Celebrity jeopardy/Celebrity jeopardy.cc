#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;

	while (getline(cin, str)) {
		cout << str << '\n';
	}
	return 0;
}