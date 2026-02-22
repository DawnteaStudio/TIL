#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool f(pair<int, int> &a, pair<int, int> &b)
{
	return a.second > b.second;
}

int main() {
    fast;

    int n;
	int a, b, c, d;
	cin >> n;

	int cnt = n * (n - 1) / 2;
	vector<pair<int, int> > vec(n + 1);
	for (int i = 0; i <= n; i++) {
		vec[i] = make_pair(i, 0);
	}
	vector<int> rank_idx(n + 1);

	for (int i = 0; i < cnt; i++) {
		cin >> a >> b >> c >> d;

		if (c == d) {
			vec[a].second++;
			vec[b].second++;
		}
		else if (c > d)
			vec[a].second += 3;
		else
			vec[b].second += 3;
	}
	sort(vec.begin() + 1, vec.end(), f);

	for(int i = 1; i <= n; i++) {
		int idx = vec[i].first;
		
		if (i != 1 && vec[i].second == vec[i - 1].second)
			rank_idx[idx] = rank_idx[vec[i - 1].first];
		else
			rank_idx[idx] = i;
	}

	for (int i = 1; i <= n; i++)
		cout << rank_idx[i] << '\n';
}
