#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res;

void solve(string& v)
{
	if (v.length() == 0)
		return;
	if (v[0] == '1')
		res = res * 2 + 1;
	else
		res = res * 2;
	v = v.substr(1);
	solve(v);
}

int main() {
	fast;
    
	string v;
	cin >> v;
	int len = v.length();
	bool flag = false;

	for (int i = 0; i < len; i++) {
		if (v[i] == '0') {
			v[i] = '1';
			flag = true;
			break;
		}
	}

	if (flag == false)
		v[len - 1] = 0;
	solve(v);
	cout << res;
}
