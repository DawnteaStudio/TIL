#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	long long a, b, c;
	cin >> a >> b >> c;

	if (b >= c)
		cout << -1;
	else {
		long long cnt = a / (c - b);
		cout << cnt + 1;
	}
}
