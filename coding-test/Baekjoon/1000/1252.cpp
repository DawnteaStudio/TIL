#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string sum(string& a, string& b) {
	int idx_a = (int)a.size() - 1, idx_b = (int)b.size() - 1, tmp = 0;
	string res;
	while (idx_a >= 0 && idx_b >= 0) {
		tmp += a[idx_a] - '0' + b[idx_b] - '0';
		if (tmp <= 1) {
			res = to_string(tmp) + res;
			tmp = 0;
		}
		else {
			res = to_string(tmp - 2) + res;
			tmp = 1;
		}
		idx_a--;
		idx_b--;
	}
	while (idx_a >= 0) {
		tmp += a[idx_a] - '0';
		if (tmp <= 1) {
			res = to_string(tmp) + res;
			tmp = 0;
		}
		else {
			res = to_string(tmp - 2) + res;
			tmp = 1;
		}
		idx_a--;
	}
	while (idx_b >= 0) {
		tmp += b[idx_b] - '0';
		if (tmp <= 1) {
			res = to_string(tmp) + res;
			tmp = 0;
		}
		else {
			res = to_string(tmp - 2) + res;
			tmp = 1;
		}
		idx_b--;
	}
	if (tmp == 1) res = '1' + res;
	int idx = 0, size = (int)res.size();
	while (idx < size && res[idx] == '0') idx++;
	if (idx == size) res = "0";
	else res = res.substr(idx, size - idx);
	return res;
}

int main()
{
	fast;
	string a, b;
    cin >> a >> b;
	cout << sum(a, b);
}