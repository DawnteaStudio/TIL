// 자전거 속도
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	double a, b, c;
	int seq = 1;
	cout << fixed;
	cout.precision(2);
	while (true) {
		cin >> a >> b >> c;
		if (b == 0) break ;
		cout << "Trip #" << seq++ << ": ";
		double dist = a * 3.141592 * b / 63360;
		c /= 3600;
		double MPH = dist  / c;
		cout << dist << " " << MPH << '\n';
	}
	return (0);
}