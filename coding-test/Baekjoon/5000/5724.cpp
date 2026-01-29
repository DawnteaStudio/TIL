#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	while (true) {
		cin >> n;
		if (n == 0)
            break ;
		int cnt = 0;
		for (int j=n; j>=1; j--)
			cnt += (int)pow(j, 2);
		cout << cnt << '\n';
	}
}