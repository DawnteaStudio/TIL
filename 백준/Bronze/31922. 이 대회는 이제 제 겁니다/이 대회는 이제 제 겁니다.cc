#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b, c;
	cin >> a >> b >> c;
	if (a + c > b)
		cout << a + c;
	else
		cout << b;
}