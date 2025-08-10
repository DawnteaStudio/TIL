#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str, tmp;
	cin >> str;
	str = str.substr(0, 5);

	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		tmp = tmp.substr(0, 5);
		if (str == tmp)
			cnt++;
	}
	cout << cnt;
}