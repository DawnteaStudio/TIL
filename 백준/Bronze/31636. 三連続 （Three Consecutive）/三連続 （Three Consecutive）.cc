#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;
	string str;
	cin >> str;

	if (n < 3)
		cout << "No";
	else {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == 'o')
				tmp++;
			else
				tmp = 0;
			if (tmp == 3) {
				cout << "Yes";
				return 0;
			}
		}
		cout << "No";
	}
}
