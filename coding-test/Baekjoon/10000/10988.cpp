#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool check(string str) {
	int size = (int)str.size();
	for (int i=0; i<size/2; i++) {
		if (str[i] != str[size-i-1]) return false;
	}
	return true;
}

int main()
{
	fast;
	string str;
	cin >> str;
	cout << check(str);
	return (0);
}