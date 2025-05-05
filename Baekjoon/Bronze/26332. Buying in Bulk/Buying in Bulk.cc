#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;


int main() {
	fast;
	int n, cnt, price;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cnt >> price;
		cout << cnt << " " << price << '\n';
		cout << cnt * price - (cnt - 1) * 2 << '\n';
	}
}
