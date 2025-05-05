#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m;
	cin >> n >> m;

	if (n == m)
		cout << n + m;
	else {
		int small = n > m ? m : n;
		cout << small * 2 + 1;
	}
}