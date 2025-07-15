#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int n, cnt, level, str, res, index = 1;

	while (true) {
		cin >> n;
		if (!n)
			break;
		cout << "Machine " << index << '\n';
		index++;
		vector<int> e(n);
		for (int i = 0; i < n; i++)
			cin >> e[i];
		while (true) {
			string name;
			res = 0;
			cin >> name >> cnt;
			if (name == "#")
				break;

			for (int j = 0; j < cnt; j++) {
				cin >> level >> str;
				res += e[level - 1] * str;
			}
			cout << name << " " << res << '\n';
		}
	}
}
