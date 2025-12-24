#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n;
	cin >> n;

	int bef, now;
	cin >> bef;
	for (int i = 1; i < n; i++) {
		cin >> now;
		if (i != n - 1)
			bef = now;
	}
	cout << 2 * now - bef;
}