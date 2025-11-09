// 출제자가 몇 명
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n; cin >> n;
	int s, c, a, r;
	int cnt = 0;
	for (int i=0; i<n; i++) {
		cin >> s >> c >> a >> r;
		if (s >= 1000 || c >= 1600 || a >= 1500 || (r != -1 && r <= 30))
			cnt++;
	}
	cout << cnt;
	return (0);
}