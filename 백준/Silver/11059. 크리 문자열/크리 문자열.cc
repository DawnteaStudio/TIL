#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int calc(string &str, int start, int end)
{
	int res = 0;

	for (int i = start; i < end; i++)
		res += str[i] - '0';
	return res;
}

bool cri(string str)
{
	int len = str.length();
	int total = calc(str, 0, len);
	int half = calc(str, 0, len / 2);
	if (total == half * 2)
		return true;
	return false;
}

int main()
{
	fast;
	string str;
	cin >> str;

	int len = str.length();
	int size = len;
	if (size % 2 != 0)
		size--;

	for (int i = size; i > 0; i -= 2) {
		for (int j = 0; j + i <= len; j++) {
			if (cri(str.substr(j, i))) {
				cout << i;
				return 0;
			}
		}
	}
}