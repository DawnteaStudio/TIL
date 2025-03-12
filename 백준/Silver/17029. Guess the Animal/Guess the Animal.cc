#include <iostream>
#include <vector>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;



int main()
{
	fast;
	int n, k, res = 0;
	cin >> n;

	vector<vector<string> > vec(n);
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp >> k;
		for (int j = 0; j < k; j++) {
			cin >> tmp;
			vec[i].push_back(tmp);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int tmp_res = 0;

			int first_size = vec[i].size();
			int second_size = vec[j].size();
			for (int p = 0; p < first_size; p++) {
				for (int q = 0; q < second_size; q++) {
					if (vec[i][p] == vec[j][q])
						tmp_res++;
				}
			}
			if (tmp_res > res)
				res = tmp_res;
		}
	}
	cout << res + 1;
}