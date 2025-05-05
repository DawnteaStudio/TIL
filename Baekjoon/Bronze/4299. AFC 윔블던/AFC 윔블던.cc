#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int	n, m;
	int win, lose;

	cin >> n >> m;
	if (n < m)
	{
		cout << -1;
		return (0);
	}
	win = (n + m) / 2;
	lose = (n - m) / 2;
	if ((n + m) % 2 != 0)
		cout << -1;
	else
		cout << win << ' ' << lose;
}
