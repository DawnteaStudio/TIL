#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool palindrom(string &str)
{
	int len = str.length();
	if (len == 1)
		return true;
	int s = 0;
	int e = len - 1;

	while (s < e) {
		if (str[s] != str[e])
			return false;
		s++;
		e--;
	}
	return true;
}

int main() {
	fast;
	long long a, b;
	cin >> a >> b;

	for (long long i = a; i <= b; i++) {
		string tmp = to_string(i);
		if (palindrom(tmp))
			cout << "Palindrome!";
		else
			cout << tmp;
		cout << '\n';
	}
}
