#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
	fast;
	int n, width, length, height, area, m;
	int w, h;
	while (true) {
		cin >> n >> width >> length >> height >> area >> m;
		if (n == 0)
			break;
		int total = (2 * width * height) + (2 * length * height) + (width * length);
		for (int i = 0; i < m; i++) {
			cin >> w >> h;
			total -= (w * h);
		}
		cout << ceil((total * n) / (double)area) << '\n';
	}
}
