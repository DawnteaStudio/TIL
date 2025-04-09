#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t; cin >> t;

	string str;
	for (int i=0; i<t; i++) {
		cin >> str;
		size_t pos = str.find('D');
		if (pos == string::npos) cout << str.size() << '\n';
		else cout << pos << '\n';
	}
	return (0);
}