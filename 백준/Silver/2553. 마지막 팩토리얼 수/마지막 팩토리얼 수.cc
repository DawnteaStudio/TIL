#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	long long n, total = 1;

		cin >> n;
		total = 1;
		for (int j = 1; j <= n; j++) {
			total *= j;
			while (total % 10 == 0)
				total /= 10;
			total %= 1000000;
		}
		cout << total % 10 << '\n';
}
