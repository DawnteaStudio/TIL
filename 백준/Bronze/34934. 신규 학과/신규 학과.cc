#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, tmp, res = 0;
	string major, str;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str >> tmp;
		if (res < tmp) {
			res = tmp;
			major = str;
		}
	}
	cout << major;
}
