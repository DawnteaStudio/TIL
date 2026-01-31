#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

char decoder(char c) {
	bool flag = c >= 'a' && c <= 'z';
	if (!flag)
        c += 'a' - 'A';

	if (c == 'y')
        c = 'a';
	else if (c == 'a')
        c = 'e';
	else if (c == 'e')
        c = 'i';
	else if (c == 'i')
        c = 'o';
	else if (c == 'o')
        c = 'u';
	else if (c == 'u')
        c = 'y';
	if (!flag)
        c -= 'a' - 'A';
	return c;
}

int main()
{
	fast;
	int n;
    cin >> n;
	cin.ignore();
	cin.clear();

	string str;
	for (int i=0; i<n; i++) {
		getline(cin, str);
		for (int j=0; j<(int)str.size(); j++)
            str[j] = decoder(str[j]);
		cout << str << '\n';
	}
}