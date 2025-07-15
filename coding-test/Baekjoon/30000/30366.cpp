#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m; cin >> n >> m;
	int time=0, a, sum=0;
	for (int i=0; i<n; i++) {
		cin >> a;
		if (sum + a <= m)
			sum += a;
		else {
			++time;
			sum = a;
		}
		cout << time << '\n';
	}
	return (0);
}
