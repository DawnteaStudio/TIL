#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct pos {
	int x=-1, y=-1;
};

int main()
{
	fast;
	int n, m; cin >> n >> m;

	pos a, b;
	int tmp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> tmp;
			if (tmp == 1) {
				if (a.x == -1)
					a = {j, i};
				else b = {j, i};
			}
		}
	}
	cout << abs(a.x - b.x) + abs(a.y - b.y);
	return (0);
}