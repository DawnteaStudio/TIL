#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, n, cnt;
	cin >> t;
	string str;
	double total, cost;
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < t; i++) {
		cin >> n;
		total = 0;
		for (int j = 0; j < n; j++) {
			cin >> str >> cnt >> cost;
			total += cnt * cost;
		}
		cout << "$" << total << '\n';
	}
}