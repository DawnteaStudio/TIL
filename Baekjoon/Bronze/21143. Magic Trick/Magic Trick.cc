#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string str; cin >> str;
	for (int i=0; i <(int)str.size() - 1; i++) {
		if (str.find(str[i], i + 1) == string::npos) continue ;
		cout << 0;
		return 0;
	}
	cout << 1;
	return 0;
}