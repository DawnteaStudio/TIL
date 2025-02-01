#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str;
	int len;
	cin >> len >> str;

	for (int i = 0; i < len; i++) {
		if (str[i] == 'J')
			cout << "O";
		else if (str[i] == 'O')
			cout << "I";
		else if (str[i] == 'I')
			cout << "J";
	}
}