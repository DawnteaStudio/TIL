#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int n, m;
	cin >> n >> m;

	long long res = 0;
	for (int i = 0; i < n + m; i++) {
		long long tmp;
		cin >> tmp;
		res += tmp;
	}
	cout << res;
}
