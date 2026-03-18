#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int f(int n)
{
	bool b = true;
	int tmp = n;
	while (true) {
		b = true;
		for (int j = 2; j * j <= tmp; j++) {
			if (tmp % j == 0) {
				b = false;
				break;
			}
		}
		if (b)
			return tmp;
		tmp++;
	}
}

int main() {
    fast;
	int n;
	cin >> n;
	cout << n << '\n';

	for (int i = 1; i < n; i++)
		cout << i << " ";
	cout << f(n);
}
