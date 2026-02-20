#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool check(int m, int seed, int x1, int x2, int a, int c) {
	return ((a * seed + c) % m == x1 && (a * x1 + c) % m == x2);
}

int main()
{
	fast;
	int m, seed, x1, x2;
	cin >> m >> seed >> x1 >> x2;
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			if (check(m, seed, x1, x2, i, j)) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
}