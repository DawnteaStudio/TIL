#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n;
	cin >> n;
	n -= 1;

	int cnt = 1;
	int res =  cnt * cnt + cnt;
	while (res != n) {
		cnt++;
		res = cnt * cnt + cnt;
	}
	cout << cnt;
}