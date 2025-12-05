#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int h;
	cin >> h;

	for (int i = 0; i < h; i++) {
		int cnt = abs(h - ((i * 2 + 1 + h) % (2 * h)));
		for (int j = 0; j < cnt; j++)
			cout << "*";
		for (int j = 0; j < (h - cnt) * 2; j++)
			cout << " ";
		for (int j = 0; j < cnt; j++)
			cout << "*";
		cout << '\n';
	}
}