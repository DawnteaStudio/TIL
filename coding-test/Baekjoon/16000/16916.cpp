#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void make_lps(vector<int> &v, string &p)
{
	int size = p.length();
	int len = 0;
	int i = 1;

	while (i < size) {
		if (p[i] == p[len]) {
			len++;
			v[i++] = len;
		}
		else {
			if (len != 0)
				len = v[len - 1];
			else
				v[i++] = 0;
		}
	}
}

bool KMP(vector<int> &lps, string &s, string &p)
{
	int start = 0;
	int j = 0;

	int s_len = s.length();
	int p_len = p.length();

	while (start < s_len) {
		if (s[start] == p[j]) {
			start++;
			j++;
			if (j == p_len)
				return true;
		}
		else {
			if (j == 0)
				start++;
			else
				j = lps[j - 1];
		}
	}
	return false;
}

int main(void) {
	fast;

	string s, p;
	cin >> s >> p;

	if (s.length() < p.length())
		cout << 0;
	else {
		vector<int> lps(p.length(), 0);
		make_lps(lps, p);
		if (KMP(lps, s, p))
			cout << 1;
		else
			cout << 0;
	}
}

