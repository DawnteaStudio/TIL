#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int t, n;
    cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		int sum = 0;
		for (int j=1; j<=n; j+=2)
            sum += j;
		cout << sum << '\n';
	}
}