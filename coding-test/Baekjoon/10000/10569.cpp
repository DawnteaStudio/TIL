#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main(void)
{
	fast;
	int t;
	cin >> t;

	int v, e;
	for (int i = 0; i < t; i++) {
		cin >> v >> e;
		cout << 2 + e - v << '\n';
	}
}
