#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
    fast;
	int n, res = 0;
	cin >> n;

	for (int i = 1; i < 500; i++) {
		for (int j = i + 1; j <= 500; j++) {
			if (j * j - i * i == n)
				res++;
		}
	}
	cout << res;
}
