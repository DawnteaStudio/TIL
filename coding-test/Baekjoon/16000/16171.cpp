#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string s, k; cin >> s >> k;
	string tmp;
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') continue ;
		tmp += s[i];
	}
	cout << (tmp.find(k) != string::npos);
}