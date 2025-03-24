#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	long long r, c, n;
	long long w, h;
	cin >> r >> c >> n;

	w = r / n;
	if (r % n != 0)
		w++;
	h = c / n;
	if (c % n != 0)
		h++;
	cout << w * h;
}