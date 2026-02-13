#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;

    int n, a = 0, b = 1;
	cin >> n;

	int s = 1;
	int now = 0;
	while (now < n) {
		now += s;
		s++;
		a++;
	}
	now -= (s - 1);
	int diff = n - now;
	for (int i = 1; i < diff; i++) {
		a--;
		b++;
	}
	cout << a << " " << b;
}
