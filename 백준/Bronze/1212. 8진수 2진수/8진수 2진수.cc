#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string conv(int num) {
	string res;
	if (num == 0)
        return "0";
	while (num) {
		int tmp = num % 2;
		res = to_string(tmp) + res;
		num /= 2;
	}
	return res;
}

int main()
{
	fast;
	string n;
    cin >> n;
	string res, zero_set = "000";
	for (int i=0; i<(int)n.size(); i++) {
		string tmp = conv(n[i] - '0');
		if (i != 0)
			tmp = zero_set.substr(0, 3 - (int)tmp.size()) + tmp;
		res += tmp;
	}
	cout << res;
}