#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m, res, index = 0;
	cin >> n >> m;

	if (n - m != 1)
		cout << "No";
	else {
		bool flag = true;
		vector<int> seq(m);
		for (int i = 0; i < m; i++)
			cin >> seq[i];
		for (int i = 1; i <= n; i++) {
			if (i != seq[index] && flag) {
				res = i;
				flag = false;
				continue;
			}
			else if (i != seq[index]) {
				cout << "No\n";
				return 0;
			}
			index++;
		}
		cout << "Yes" << '\n' << res;
	}
}