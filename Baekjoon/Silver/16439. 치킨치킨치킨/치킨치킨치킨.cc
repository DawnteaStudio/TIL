#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, m, res;

void solve(vector<vector<int> > &vec, vector<int> &choose, int depth)
{
	if (depth == 3) {
		int tmp = 0;
		for (int i = 0; i < n; i++)
			tmp += max(max(vec[i][choose[0]], vec[i][choose[1]]), vec[i][choose[2]]);
		if (tmp > res)
			res = tmp;
		return ;
	}
	for (int i = 0; i < m; i++) {
		if (depth == 1)
			if (choose[0] == i)
				continue;
		if (depth == 2)
			if (choose[0] == i || choose[1] == i)
				continue;
		choose[depth] = i;
		solve(vec, choose, depth + 1);
	}
}

int main()
{
	fast;
	cin >> n >> m;

	vector<vector<int> > vec(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> vec[i][j];
	}

	vector<int> choose(3);
	solve(vec, choose, 0);
	cout << res;
}