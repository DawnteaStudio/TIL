#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void case4(string &s) {
	for (int i=0; i<(int)s.size(); i++)
		s[i] = 'A';
}

void case3(string &s) {
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i] == 'D' || s[i] == 'F')
			s[i] = 'C';
	}
}

void case2(string &s) {
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i] == 'C' || s[i] == 'D' || s[i] == 'F')
			s[i] = 'B';
	}
}

void case1(string &s) {
	for (int i=0; i<(int)s.size(); i++) {
		if (s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'F')
			s[i] = 'A';
	}
}

int main()
{
	fast;
	string s; cin >> s;
	if (s.find('A') != string::npos) case1(s);
	else if (s.find('B') != string::npos) case2(s);
	else if (s.find('C') != string::npos) case3(s);
	else case4(s);
	cout << s;
	return (0);
}