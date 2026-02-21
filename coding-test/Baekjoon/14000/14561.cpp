#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool f(string &s)
{
	int len = s.length();
	int start = 0, end = len - 1;

	while (start < end) {
		if (s[start] != s[end])
			return false;
		start++;
		end--;
	}
	return true;
}

int main() {
    fast;

    long long n, num, d, p;
	cin >> n;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> num >> d;
		str = "";

		while (num > 0) {
			p = num % d;
			if (p < 10)
				str = to_string(p) + str;
			else
				str = (char)('A' + (p - 10)) + str;
			num /= d;
		}
		if (f(str))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}
