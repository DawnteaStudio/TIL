#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a[2], b[2], c[2], x, y;

	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];
	cin >> c[0] >> c[1];
	if (a[0] == b[0]) y = c[0];
	else if (a[0] == c[0]) y = b[0];
	else y = a[0];
	if (a[1] == b[1]) x = c[1];
	else if (a[1] == c[1]) x = b[1];
	else x = a[1];
	cout << y << ' ' << x;
	return (0);
}