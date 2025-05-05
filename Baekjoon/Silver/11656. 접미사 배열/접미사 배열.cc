#include <iostream>
#include <string>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string make_str(string s, int start, int end)
{
	string str = "";

	for (int i = start; i < end; i++)
		str += s[i];
	return str;
}

int main()
{
	fast;
	string str;

	cin >> str;
	int len = str.length();
	string arr[len];
	for (int i = 0; i < len; i++)
		arr[i] = make_str(str, i, len);
	
	sort(arr, arr + len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << '\n';
}
