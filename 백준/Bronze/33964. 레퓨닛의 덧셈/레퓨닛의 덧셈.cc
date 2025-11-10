#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
	cin >> n >> m;

	int mx = max(n, m);
	int diff = abs(n - m);
	for (int i = 0; i < diff; i++)
		cout << 1;
	for (int i = 0; i < mx - diff; i++)
		cout << 2;
}
