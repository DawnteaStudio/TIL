#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
    cin >> n;
	int cnt = 0;
	for (int i=3; i<=n; i++) {
		int tmp = i;
		while (tmp) {
			if (tmp % 10 != 0 && (tmp % 10) % 3 == 0)
                cnt++;
			tmp /= 10;
		}
	}
	cout << cnt;
}