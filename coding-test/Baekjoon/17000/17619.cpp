#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<pair<int, pair<int, int> > > interval;
vector<int> parent;
vector<int> ranking;

bool cmp(pair<int, pair<int, int> >& a, pair<int, pair<int, int> >& b)
{
	if (a.second.first < b.second.first)
		return true;
	else if (a.second.first > b.second.first)
		return false;
	return a.second.second < b.second.second;
}

void make_set(int n)
{
	parent.resize(n);
	interval.resize(n);
	ranking.resize(n, 0);

	for (int i = 0; i < n; i++)
		parent[i] = i;
}

int ft_find(int x)
{
	if (parent[x] != x)
		parent[x] = ft_find(parent[x]);
	return parent[x];
}

void ft_union(int a, int b)
{
	a = ft_find(a);
	b = ft_find(b);

	if (a != b) {
		if (ranking[a] < ranking[b])
			swap(a, b);
		parent[b] = a;
		if (ranking[a] == ranking[b])
			ranking[a]++;
	}
}

int main()
{
	fast;
	int n, q;
	cin >> n >> q;

	make_set(n);
	int l, r, h;
	for (int i = 0; i < n; i++) {
		cin >> l >> r >> h;

		interval[i] = make_pair(i, make_pair(l, r));
	}
	sort(interval.begin(), interval.end(), cmp);

	int right = interval[0].second.second;
	for (int i = 1; i < n; i++) {
		if (interval[i].second.first <= right) {
			right = max(interval[i].second.second, right);
			ft_union(interval[i - 1].first, interval[i].first);
		}
		else {
			right = max(interval[i].second.second, right);
		}
	}
	int x, y;
	for (int i = 0; i < q; i++) {
		cin >> x >> y;

		if (ft_find(x - 1) == ft_find(y - 1))
			cout << 1;
		else
			cout << 0;
		cout << '\n';
	}
}
