#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	string tmp;

	while (true) {
		getline(cin, tmp);

		if (tmp == "***")
			break;
		reverse(tmp.begin(), tmp.end());
		cout << tmp << '\n';
	}
}