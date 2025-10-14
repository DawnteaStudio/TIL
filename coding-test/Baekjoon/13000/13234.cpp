#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool string_to_bool(string str) {
	return str == "true";
}

int main()
{
	fast;
	string str; cin >> str;
	bool result = string_to_bool(str);
	string bit_oper; cin >> bit_oper;
	cin >> str;
	if (bit_oper == "AND") result &= string_to_bool(str);
	else result |= string_to_bool(str);

	if (result) cout << "true";
	else cout << "false";
}
