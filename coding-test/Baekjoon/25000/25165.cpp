#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m, c, d, sr, sc;
	cin >> n >> m >> c >> d >> sr >> sc;
	if (sr > 1 && sr < n)
		cout << "NO...\n";
	else if (sr == 1) {
		if (c >= sc && d == 0)
			cout << "NO...\n";
		else if (c <= sc && d == 1)
			cout << "NO...\n";
		else
			cout << "YES!\n";
	}
	else {
		if (d == 0) {
			if (n % 2 == 0)
				cout << "NO...\n";
			else if (sc == m)
				cout << "NO...\n";
			else
				cout << "YES!\n";
		}
		else {
			if (n % 2 == 1)
				cout << "NO...\n";
			else if (sc == m)
				cout << "NO...\n";
			else
				cout << "YES!\n";
		}
	}
}