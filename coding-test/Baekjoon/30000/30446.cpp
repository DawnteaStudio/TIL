#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(const string& a, const string& b)
{
	int len_a = a.length();
	int len_b = b.length();

	if (len_a == len_b)
		return a > b;
	return len_a > len_b;
}

int main() {
	fast;
	long long n, cnt = 0;
	cin >> n;

	string s_n = to_string(n);
	string tmp, res1, res2;

	if (n < 10)
		cout << n;
	else {
		for (int i = 1; i < n; i++) {
			res1 = to_string(i);
			tmp = res1;
			reverse(tmp.begin(), tmp.end());
			res2 = res1 + tmp;
			if (cmp(res1 + tmp.substr(1), s_n))
				break;
			if (res1[res1.length() - 1] == tmp[0])
				cnt++;
			if (cmp(res2, s_n) == false)
				cnt++;
		}
		cout << cnt;
	}
}
