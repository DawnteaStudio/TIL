#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int a, branch, delete_b;

	while (true) {
		cin >> a;
		if (a == 0) break ;

		int res = 1;
		for (int i=0; i<a; i++) {
			cin >> branch >> delete_b;
			res = res * branch - delete_b;
		}
		cout << res << '\n';
	}
}
