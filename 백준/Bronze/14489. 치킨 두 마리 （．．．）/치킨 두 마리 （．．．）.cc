#include <iostream>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int a, b, chicken;
	cin >> a >> b >> chicken;

	if (a + b >= 2 * chicken)
		cout << a + b - 2 * chicken;
	else
		cout << a + b;
}
