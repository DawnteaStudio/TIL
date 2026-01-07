#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int p, q, a, b;
	cin >> p >> q >> a >> b;
	if (q <= p)
		cout << q * a;
	else
		cout << p * a + (q - p) * b;
}