#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str ,res;
	cin >> str;
	int len = str.length();

	int u = 0, d = 0, p = 0, c = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'U')
			u++;
		else if (str[i] == 'D')
			d++;
		else if (str[i] == 'P')
			p++;
		else if (str[i] == 'C')
			c++;
	}
	if (u + c > (d + p) / 2 + (d + p) % 2)
		res += "U";
	if (d + p > 0)
		res += "DP";
	if (res.empty())
		res = "C";
	cout << res;
}