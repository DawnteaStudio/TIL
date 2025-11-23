#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m, a, b;
	cin >> n >> m >> a >> b;

	if (m >= n * 3)
		cout << 0;
	else
		cout << (n * 3 - m) * a + b;
}
