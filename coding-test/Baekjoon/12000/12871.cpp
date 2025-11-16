#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    string a, b;
	cin >> a >> b;
	if (a.length() > b.length())
		swap(a, b);

	while (b.length() >= 0) {
		int len = a.length();
		if (a == b.substr(0, len))
			b = b.substr(len);
		else
			break;
		if (a.length() > b.length())
			swap(a, b);
		if (a.length() == 0) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}
