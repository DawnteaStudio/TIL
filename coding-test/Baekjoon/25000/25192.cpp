#include <iostream>
#include <map>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, cnt = 0;
	cin >> n;
	map<string, bool> m;

	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == "ENTER")
			m.clear();
		else {
			if (m.find(tmp) == m.end()) {
				cnt++;
				m.insert(make_pair(tmp, true));
			}
		}
	}
	cout << cnt;
}