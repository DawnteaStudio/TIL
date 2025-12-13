#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m;
	cin >> n >> m;

	vector<int> liq(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> liq[i];
	
	for (int i = 0; i < m; i++) {
		int l, h;
		cin >> l >> h;

		int most = 0;
		for (int j = 1; j <= n; j++) {
			if (liq[j] > most)
				most = liq[j];
		}

		if (liq[h] == most)
			continue;
		liq[l]--;
	}

	for (int i = 1; i <= n; i++)
		cout << liq[i] << " ";
}
