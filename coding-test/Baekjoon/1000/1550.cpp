#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str; cin >> str;

	int tmp = 0, res = 0;
	for (int i=(int)str.size() - 1; i>=0; i--) {
		int num;
		if (str[i] >= '0' && str[i] <= '9') num = str[i] - '0';
		else num = str[i] - 'A' + 10;
		res += num << tmp;
		tmp += 4;
	}
	cout << res;


	return (0);
}