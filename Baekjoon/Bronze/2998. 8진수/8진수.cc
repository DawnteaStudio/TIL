#include <iostream>
#include <string>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	string input;
	string ans = "";
	cin >> input;
	map<string, string> m;
	string arr[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

	for (int i=0; i<8; i++) {
		m.insert(make_pair(arr[i], to_string(i)));
	}

	int add = 3 - (input.length() % 3);
	if (add == 3)
		add = 0;
	for (int i = 0; i < add; i++)
		input = "0" + input;
	for (int i = 0; i < input.length(); i += 3)
	{
		string piece = input.substr(i, 3);
		ans += m[piece];
	}
	cout << ans;
}
