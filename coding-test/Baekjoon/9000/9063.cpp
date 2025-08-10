#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void)
{
	fast;
	int n;
	cin >> n;

	int w_l, w_r;
	int h_l, h_h;
	int x, y;
	if (n == 1)
		cout << 0;
	else {
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			if (i == 0) {
				w_l = w_r = x;
				h_l = h_h = y;
			}
			else {
				if (x < w_l)
					w_l = x;
				if (x > w_r)
					w_r = x;
				if (y < h_l)
					h_l = y;
				if (y > h_h)
					h_h = y;
			}
		}
		cout << (w_r - w_l) * (h_h - h_l);
	}
}
