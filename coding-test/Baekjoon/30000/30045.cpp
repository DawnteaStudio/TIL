#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

int main()
{
	fast;
	string str, tmp;
	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		int len= str.length();
		for (int j = 0; j < len - 1; j++) {
			tmp = str.substr(j, 2);
			if (tmp == "01" || tmp == "OI") {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}