#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool	cmp(long long a, long long b)
{
	return (a > b);
}

int main()
{
	fast;
	int	n, k;
	cin >> n >> k;

	long long res = 0, tmp;
	vector<long long> p_v;
	vector<long long> n_v;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp < 0)
			n_v.push_back(tmp);
		else
			p_v.push_back(tmp);
	}
	sort(n_v.begin(), n_v.end());
	sort(p_v.begin(), p_v.end(), cmp);
	for (int i = 0; i < n_v.size(); i += k)
		res += (n_v[i] * -2);
	for (int i = 0; i < p_v.size(); i += k)
		res += p_v[i] * 2;
	cout << res;
}