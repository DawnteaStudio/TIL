#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b; cin >> a >> b;
	if (a >= 20 && a <= 23) a -= 24;
	cout << b - a;
}