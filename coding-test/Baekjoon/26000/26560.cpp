#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n; cin >> n;
	cin.ignore();
	string str;
	for (int i=0; i<n; i++) {
		getline(cin, str);
		if (str[str.size() - 1] != '.') str += '.';
		cout << str << '\n';
	}
	return (0);
}