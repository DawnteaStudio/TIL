#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res = -1, n, k;

void solve(vector<pair<int, int> >& v, vector<int>& rest)
{
	int tmp = -1;
	int ans_x, ans_y;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int x = v[i].first;
		int y = v[i].second;
		tmp = -1;

		for (int j = 0; j < k; j++) {
			int r_x = v[rest[j]].first;
			int r_y = v[rest[j]].second;

			ans_x = x - r_x;
			ans_y = y - r_y;

			if (ans_x < 0)
				ans_x *= -1;
			if (ans_y < 0)
				ans_y *= -1;
			
			if (tmp == -1)
				tmp = ans_x + ans_y;
			else if (tmp > ans_x + ans_y)
				tmp = ans_x + ans_y;
		}
		if (ans < tmp)
			ans = tmp;
	}
	if (res == -1)
		res = ans;
	else if (res > ans)
		res = ans;
}

void get(vector<pair<int, int> >& v, vector<int>& rest, int depth)
{
	int idx = 0;
	if (depth == k)
		solve(v, rest);
	else {
		if (depth != 0)
			idx = rest[depth - 1] + 1;

		for (int i = idx; i < n; i++) {
			rest[depth] = i;
			get(v, rest, depth + 1);
		}
	}
}

int main() {
	fast;
	cin >> n >> k;

	vector<pair<int, int> > v(n);
	vector<int> rest(3);
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v[i] = { x, y };
	}
	get(v, rest, 0);
	cout << res;
}
