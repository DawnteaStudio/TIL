#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n, tmp, t;
	char c;
	cin >> n;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> c >> tmp;
		if (c == '+')
			n += tmp;
		else
			n -= tmp;
	}
	cout << n;
}