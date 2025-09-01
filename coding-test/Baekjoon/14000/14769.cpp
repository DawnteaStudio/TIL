#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
    int n;
	cin >> n;

	string a, b;
	int tmp;
	vector<pair<int, string> > vec;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a[0] >= '0' && a[0] <= '9') {
			tmp = stoi(a);
			vec.push_back({tmp / 2, b});
		}
		else {
			tmp = stoi(b);
			vec.push_back({tmp, a});
		}
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		cout << vec[i].second << '\n';
	}
}
