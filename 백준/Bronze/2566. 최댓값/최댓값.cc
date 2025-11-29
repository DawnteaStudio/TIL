#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int res = -1, r, c, tmp;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> tmp;
			if (tmp > res) {
				res = tmp;
				r = i;
				c = j;
			}
		}
	}
	cout << res << '\n' << r << " " << c;
}
