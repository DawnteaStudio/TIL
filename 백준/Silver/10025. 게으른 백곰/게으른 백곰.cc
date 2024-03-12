#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second < b.second)
		return (true);
	else
		return (false);
}

int main()
{
	fast;
	int n, k, res = 0;
	int g, x;
	cin >> n >> k;

	vector<pair<int, int> > v(n);
	vector<pair<int, int> > prefix_v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> g >> x;
		v[i].first = g;
		prefix_v[i].first = g;
		v[i].second = x;
		prefix_v[i].second = x;
	}

	sort(v.begin(), v.end(), comp);
	sort(prefix_v.begin(), prefix_v.end(), comp);

	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			prefix_v[i].first += prefix_v[i - 1].first;
	}

	int start = 0, end = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].second > v[start].second + 2 * k)
		{
			end = i - 1;
			break;
		}
		else
			end = i;
	}

	for (int i = 0; i < n; i++)
	{
		if (res < prefix_v[end].first - prefix_v[start].first + v[start].first)
			res = prefix_v[end].first - prefix_v[start].first + v[start].first;
		start++;
		while (end + 1 < n && v[end + 1].second <= v[start].second + 2 * k)
			end++;
	}
	cout << res;
}