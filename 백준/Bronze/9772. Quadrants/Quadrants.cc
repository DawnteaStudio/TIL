#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	double x, y;
	while (true) {
		cin >> x >> y;
		if (x == 0.0 || y == 0.0) cout << "AXIS\n";
		if (x == 0.0 && y == 0.0) break ;
		if (x > 0.0 && y > 0.0) cout << "Q1\n";
		else if (x > 0.0 && y < 0.0) cout << "Q4\n";
		if (x < 0.0 && y > 0.0) cout << "Q2\n";
		if (x < 0.0 && y < 0.0) cout << "Q3\n";
	}
	return 0;
}
