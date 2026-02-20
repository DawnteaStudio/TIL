#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool check(string &s) {
	int size = (int)s.size();
	for (int i=0; i<=size/2; i++) {
		if (s[i] != s[size - i - 1])
            return false;
	}
	return true;
}

int main()
{
	fast;
	string s;
	long long k;
	cin >> s >> k;
	if (check(s))
        cout << "YES";
	else
        cout << "NO";
}