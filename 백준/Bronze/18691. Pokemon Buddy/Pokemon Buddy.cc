#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, g, c, e;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> g >> c >> e;
		if (c >= e)
			cout << 0 << '\n';
		else
		{
			g = 2 * g - 1;
			cout << (e - c) * g << '\n';
		}
	}
}
