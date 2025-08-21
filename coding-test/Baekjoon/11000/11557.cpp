#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m, d;



int main(void) {
	fast;

	int t;
	cin >> t;

	string ans;
	int top;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		top = 0;
		for (int j = 0; j < n; j++) {
			string tmp;
			int cnt;
			cin >> tmp >> cnt;
			if (cnt > top) {
				top = cnt;
				ans = tmp;
			}
		}
		cout << ans << '\n';
	}
}