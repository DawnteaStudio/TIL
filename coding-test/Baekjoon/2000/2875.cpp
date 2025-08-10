#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m, k;
	cin >> n >> m >> k;

	int max_team = min(n / 2, m), sum = n + m;
	int tmp = sum - max_team * 3;
	while (tmp < k) {
		max_team--;
		tmp += 3;
	}
	cout << max_team;
	return (0);
}