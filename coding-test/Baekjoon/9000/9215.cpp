#include <iostream>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int get_g(int a, int b)
{
	if (a == 0 || b == 0)
		return 1;
	int tmp_a = a;
	a = max(a, b);
	b = min(tmp_a, b);
	int r = 1;
	while (r != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void parse(string &input, int &nn, int &d)
{
	int n_tmp = 0, d_tmp = 0, i = 0;
	int len = input.length();

	for (i = 0; i < len; i++) {
		if (input[i] == '/')
			break;
		n_tmp = n_tmp * 10 + input[i] - '0';
	}
	i++;

	for (; i < len; i++) {
		d_tmp = d_tmp * 10 + input[i] - '0';
	}
	if (d == 0) {
		d = d_tmp;
		nn = n_tmp;
	}
	else {
		int g = get_g(d, d_tmp);
		int x_before = d_tmp / g;
		int x_end = d / g;

		d = (d * d_tmp) / g;
		nn = nn * x_before;
		n_tmp = n_tmp * x_end;
		nn += n_tmp;
	}
}

void parse_w(string &input, int &w)
{
	int res = 0, idx = 0;
	int len = input.length();

	while (idx < len) {
		if (input[idx] == ',')
			break;
		res = res * 10 + input[idx] - '0';
		idx++;
	}
	if (idx + 1 < len)
		input = input.substr(idx + 1);
	w += res;
}

int main() {
	fast;
    
	int n, w, nn, d, idx = 1;
	string input;
	while (true) {
		cin >> n;
		w = 0, nn = 0, d = 0;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			cin >> input;
			if (input.find("/") == string::npos)
				parse_w(input, w);
			else {
				if (input.find(",") != string::npos)
					parse_w(input, w);
				parse(input, nn, d);
			}
		}
		if (d != 0) {
			w += nn / d;
			nn = nn % d;
			int g = get_g(nn, d);
			nn /= g;
			d /= g;
		}

		cout << "Test " << idx++ << ": ";
		if (w == 0) {
			if (nn == 0)
				cout << 0;
			else
				cout << nn << "/" << d;
			cout << '\n';
		}
		else {
			cout << w;
			if (nn != 0)
				cout << "," << nn << "/" << d;
			cout << '\n';
		}
	}
}
