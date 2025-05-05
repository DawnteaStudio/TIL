#include <iostream>
#include <vector>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, d, k, c, res = 0;
	cin >> n >> d >> k >> c;

	vector<int> v(n);
	vector<int> spc;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int end = k - 1;
	for (int i = 0; i < k; i++)
	{
		if (find(spc.begin(), spc.end(), v[i]) == spc.end())
			spc.push_back(v[i]);
	}
	if (res < spc.size())
	{
		res = spc.size();
		if (find(spc.begin(), spc.end(), c) == spc.end())
			res++;
	}
	if (n == k)
	{
		cout << res;
		return (0);
	}

	for (int start = 0; start < n; start++)
	{
		if (start < end)
		{
			if (find(v.begin() + start + 1, v.begin() + end + 1, v[start]) == v.begin() + end + 1)
				spc.erase(find(spc.begin(), spc.end(), v[start]));
		}
		else
		{
			if (find(v.begin() + start + 1, v.end(), v[start]) == v.end() && find(v.begin(), v.begin() + end + 1, v[start]) == v.begin() + end + 1)
				spc.erase(find(spc.begin(), spc.end(), v[start]));
		}

		if (end + 1 < n)
			end++;
		else
			end = 0;
		if (find(spc.begin(), spc.end(), v[end]) == spc.end())
			spc.push_back(v[end]);
		if (res <= spc.size())
		{
			res = spc.size();
			if (find(spc.begin(), spc.end(), c) == spc.end())
				res++;
		}
	}
	cout << res;
}