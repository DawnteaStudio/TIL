#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	long long p1, q1, p2, q2;
	cin >> p1 >> q1 >> p2 >> q2;

	if ((p1 * p2) % (q1 * q2 * 2) == 0)
		cout << 1;
	else
		cout << 0;
}
