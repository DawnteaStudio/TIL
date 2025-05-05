#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b, c, d, e, f, g, h;
	int A, B;

	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	A = a + b + c + d;
	B = e + f + g + h;
	if (A > B)
		cout << A;
	else
		cout << B;
}