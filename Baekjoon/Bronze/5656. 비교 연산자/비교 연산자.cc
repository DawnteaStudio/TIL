#include <iostream>
#include <string>
#include <sstream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	string s;
	int a , b, index = 1;
	string op;
	while (getline(cin, s))
	{
		stringstream ss(s);
		ss >> a >> op >> b;
		if (op == "E")
			break;
		if (op == "<") {
			if (a < b)
				cout << "Case " << index << ": true" << '\n';
			else
				cout << "Case " << index << ": false" << '\n';
		}
		else if (op == "<=") {
			if (a <= b)
				cout << "Case " << index << ": true" << '\n';
			else
				cout << "Case " << index << ": false" << '\n';
		}
		else if (op == ">") {
			if (a > b)
				cout << "Case " << index << ": true" << '\n';
			else
				cout << "Case " << index << ": false" << '\n';
		}
		else if (op == ">=") {
			if (a >= b)
				cout << "Case " << index << ": true" << '\n';
			else
				cout << "Case " << index << ": false" << '\n';
		}
		else if (op == "==") {
			if (a == b)
				cout << "Case " << index << ": true" << '\n';
			else
				cout << "Case " << index << ": false" << '\n';
		}
		else if (op == "!=") {
			if (a != b)
				cout << "Case " << index << ": true" << '\n';
			else
				cout << "Case " << index << ": false" << '\n';
		}
		else {
			break;
		}
		index++;
	}
}
