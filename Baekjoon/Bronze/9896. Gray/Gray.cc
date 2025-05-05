#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;

	string s, res;
	cin >> s;

	res.push_back(s[0]);
	for (int i = 1; i < n; i++)
		res.push_back('0' + (s[i - 1] + s[i] - '0' - '0') % 2);
	cout << res << '\n';
}
