#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, n, cnt=0; cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		if (n % 2 == 0) cnt += n / 2;
		else cnt += n / 2 + 1;
	}
	cout << cnt;
	return (0);
}