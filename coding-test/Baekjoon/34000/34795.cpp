#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int m, d, res = 0;
	cin >> m >> d;
	if (d % m)
		res++;
	res += d / m;
	cout << res;
}
