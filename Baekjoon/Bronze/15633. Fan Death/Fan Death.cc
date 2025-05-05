#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

void solve(int n)
{
	int res = 0;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			res += i;
	}
	cout << (res * 5) - 24;
}

int main() {
	fast;
	int n;
	cin >> n;

	solve(n);
}
