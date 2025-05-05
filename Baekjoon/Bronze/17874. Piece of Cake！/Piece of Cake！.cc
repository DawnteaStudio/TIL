#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, h, v;
	cin >> n;
	cin >> h >> v;
	if (n - h > h)
		h = n - h;
	if (n - v > v)
		v = n - v;
	cout << h * v * 4;
}
