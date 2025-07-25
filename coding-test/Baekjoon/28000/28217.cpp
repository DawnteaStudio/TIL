#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, input;
	cin >> n;

	vector<vector<int> > a(n);
	vector<vector<int> > b(n);

	vector<vector<int> > a_rev(n);
	vector<vector<int> > b_rev(n);

	vector<string> a_case(6, "");
	vector<string> b_case(6, "");

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> input;
			a[i].push_back(input);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> input;
			b[i].push_back(input);
		}
	}

	for (int i = 0; i < n; i++) {
		a_rev[i] = a[i];
		b_rev[i] = b[i];

		reverse(a_rev[i].begin(), a_rev[i].end());
		reverse(b_rev[i].begin(), b_rev[i].end());
	}

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			a_case[index * 2] += (char)(a[i][j] + '0');
			b_case[index * 2] += (char)(b[i][j] + '0');
			a_case[index * 2 + 1] += (char)(a_rev[i][j] + '0');
			b_case[index * 2 + 1] += (char)(b_rev[i][j] + '0');
		}
	}

	index++;
	for (int j = 0; j < n; j++) {
		int tmp = j;
		for (int i = n - 1; i >= 0; i--) {
			if (tmp < 0)
				break;
			a_case[index * 2] += a[i][tmp] + '0';
			b_case[index * 2] += b[i][tmp] + '0';
			a_case[index * 2 + 1] += a_rev[i][tmp] + '0';
			b_case[index * 2 + 1] += b_rev[i][tmp] + '0';
			tmp--;
		}
	}

	index++;
	for (int j = n - 1; j >= 0; j--) {
		int tmp = j;
		for (int i = n - 1; i >= 0; i--) {
			if (tmp > n - 1)
				break;
			a_case[index * 2] += a[i][j] + '0';
			b_case[index * 2] += b[i][j] + '0';
			a_case[index * 2 + 1] += a_rev[i][j] + '0';
			b_case[index * 2 + 1] += b_rev[i][j] + '0';
			tmp++;
		}
	}

	int cnt = 99999999;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			int len = a_case[0].length();
			int tmp = 0;

			for (int k = 0; k < len; k++) {
				if (a_case[i][k] != b_case[j][k])
					tmp++;
			}
			if (cnt > tmp)
				cnt = tmp;
		}
	}
	cout << cnt;
}
