// Sequences
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break ;
		int tmp = 0;
		while (a + tmp * b < c) tmp++;
		if (a + tmp * b == c) cout << tmp + 1 << '\n';
		else cout << 'X' << '\n';
	}
	return (0);
}