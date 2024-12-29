#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b, c;

	int cnt = 0;
	cin >> a >> b >> c;

	if (b - a > c - b)
		cout << b - a - 1;
	else
		cout << c - b - 1;
}