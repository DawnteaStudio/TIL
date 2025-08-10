#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n;
bool done = false;

bool is_bad(string &now)
{
	int len = now.length();
	bool flag;
	for (int i = 1; i <= len / 2; i++) {
		flag = false;
		for (int j = 0; j < i; j++) {
			if (now[len - 1 - j] != now[len - 1 - j - i]) {
				flag = true;
				break;
			}
			if (j == i - 1 && flag == false)
				return false;
		}
	}
	return true;
}

void f(string now, int depth)
{
	if (is_bad(now) == false || done)
		return;
	if (depth == n) {
		done = true;
		cout << now;
		return;
	}
	
	string tmp;
	for (int i = '1'; i <= '3'; i++) {
		tmp = now;
		tmp += (char)i;
		f(tmp, depth + 1);
	}
}

int main()
{
	cin >> n;
	string tmp = "";
	f(tmp, 0);
}

