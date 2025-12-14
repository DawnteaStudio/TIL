#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, miss = 0, blank = 0;
	cin >> n;

	int tmp;
	cin >> tmp;
	for (int i = 1; i < n; i++) {
		int now;
		cin >> now;

		if (tmp > now)
			blank += tmp - now;
		else
			miss += now - tmp;
		tmp = now;
	}
	cout << blank << " " << miss;
}
