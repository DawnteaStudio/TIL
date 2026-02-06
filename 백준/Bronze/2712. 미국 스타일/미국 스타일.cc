// 미국 스타일
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
    cin >> n;
	double value;
	string unit;
	cout << fixed;
	cout.precision(4);
	for (int i=0; i<n; i++) {
		cin >> value >> unit;
		if (unit == "kg")
			cout << value * 2.2046 << " lb\n";
		else if (unit == "lb")
			cout << value * 0.4536 << " kg\n";
		else if (unit == "l")
			cout << value * 0.2642 << " g\n";
		else
			cout << value * 3.7854 << " l\n";
	}
}