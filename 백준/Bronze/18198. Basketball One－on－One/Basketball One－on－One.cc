#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str; cin >> str;
	int a=0, b=0;
	for (int i=0; i<(int)str.size(); i+=2) {
		if (str[i] == 'A') a += str[i + 1] - '0';
		else b += str[i + 1] - '0';
	}
	if (a > b) cout << 'A';
	else cout << 'B';
	return (0);
}