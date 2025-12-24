#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		m -= 4;
		if (m % 2 == 0)
			cout << "2025";
		else {
			cout << "42025";
			m--;
		}
		for (int j = 0; j < m; j++)
			cout << "0";
		cout << '\n';
	}
}
