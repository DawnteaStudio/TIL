#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, tmp;
	cin >> n;

	int res = 0;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		if (n - tmp <= 1000)
			res++;
	}
	cout << res;
}
