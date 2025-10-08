#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int sx, sy, ex, ey, px, py;
	cin >> sx >> sy >> ex >> ey >> px >> py;

	if (sx == ex) {
		if (sx != px)
			cout << 0;
		else {
			if (sy < py && ey < py)
				cout << 0;
			else if (sy > py && ey > py)
				cout << 0;
			else
				cout << 2;
		}
	}
	else if (sy == ey) {
		if (sy != py)
			cout << 0;
		else {
			if (sx < px && ex < px)
				cout << 0;
			else if (sx > px && ex > px)
				cout << 0;
			else
				cout << 2;
		}
	}
	else {
		cout << 1;
	}
}
