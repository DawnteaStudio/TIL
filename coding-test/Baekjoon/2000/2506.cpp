#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
	int n, res = 0, tmp, score = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == 1)
			res += ++score;
		else
			score = 0;
	}
	cout << res;
}