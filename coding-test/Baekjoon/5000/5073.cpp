#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int a, b, c;

	while (true) {
		cin >> a >> b >> c;
		if (a == 0)
			break;
		if (a == b && b == c)
			cout << "Equilateral\n";
		else {
			int tmp;
			if (a < b) {
				tmp = a;
				a = b;
				b = tmp;
			}
			if (a < c) {
				tmp = a;
				a = c;
				c = tmp;
			}
			if (a >= b + c)
				cout << "Invalid\n";
			else if (a == b || b == c || a == c)
				cout << "Isosceles\n";
			else
				cout << "Scalene\n";
		}
	}
}