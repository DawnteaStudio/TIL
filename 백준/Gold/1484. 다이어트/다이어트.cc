#include <iostream>
#include <vector>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

using ll = long long;

ll ft_pow(ll num)
{
	return (num * num);
}

int main()
{
	fast;
	ll g, val;
	cin >> g;
	vector<ll> v;
	vector<ll> res;

	if (g == 1)
	{
		cout << -1;
		return (0);
	}
	for (ll i = 0; i < g; i++)
		v.push_back(i);
	
	int end = g - 1, start = g - 2;
	while (end != 1)
	{
		val = ft_pow(v[end]) - ft_pow(v[start]);
		if (val > g)
			end--;
		else if (val < g)
		{
			start--;
			if (start == 0)
				break;
		}
		else
		{
			res.push_back(v[end]);
			end--;
		}
	}
	if (res.size() == 0)
	{
		cout << -1;
		return (0);
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << '\n';
}