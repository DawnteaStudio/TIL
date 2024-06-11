#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)
		return false;
	else if (a.second == b.second)
	{
		if (a.first > b.first)
			return false;
	}
	return true;
}

int main()
{
	fast;
	int n, tmpx, tmpy;
	cin >> n;

	vector<pair<int, int> > m;
	for (int i = 0; i < n; i++)
	{
		cin >> tmpx >> tmpy;
		m.push_back({tmpx,tmpy});
	}
	sort(m.begin(), m.end(), comp);
	for (auto i = m.begin(); i != m.end(); i++)
		cout << i->first << ' ' << i->second << '\n';
}