#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;



int main()
{
	fast;
	int cnt = 0;
	string str;
	cin >> str;

	while (!str.empty()) {
		int index = str.find("DKSH");
		if (index < 0)
			break;
		cnt++;
		str = str.substr(index + 4);
	}
	cout << cnt;
}
