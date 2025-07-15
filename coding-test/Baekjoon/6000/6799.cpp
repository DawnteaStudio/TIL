#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool cmp(pair<int, string> &a, pair<int, string> &b)
{
	if (a.first > b.first)
		return true;
	else if (a.first < b.first)
		return false;
	return a.second < b.second;
}

int main()
{
	fast;

	int n, r, s, d, res;
	cin >> n;
	if (n == 0)
		return 0;

	string name;
	vector<pair<int, string> > v;
	for (int i = 0; i < n; i++) {
		cin >> name >> r >> s >> d;
		res = 2 * r + 3 * s + d;
		v.push_back(make_pair(res, name));
	}
	if (n == 1)
		cout << name;
	else {
		sort(v.begin(), v.end(), cmp);
		cout << v[0].second << '\n' << v[1].second;
	}
}
