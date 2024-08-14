#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a[3];

	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	if (a[2] == a[0] + a[1]) cout << 1;
	else if (a[2] == a[0] * a[1]) cout << 2;
	else cout << 3;
}
