#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break ;
		if (n > 1000000 && n <= 5000000) cout << (int)(n * 0.9);
		else if (n > 5000000) cout << (int)(n * 0.8);
		else cout << n;
		cout << '\n';
	}
	return (0);
}
