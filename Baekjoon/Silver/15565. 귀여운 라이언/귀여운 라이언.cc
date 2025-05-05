#include <iostream>
#include <vector>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, k, cnt = 0, res;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int start = 0, end;
	while (start < n && v[start] != 1)
		start++;
	end = start;
	while (end < n && cnt != k)
	{
		if (v[end] == 1)
			cnt++;
		if (cnt != k)
			end++;
	}
	if (cnt != k)
	{
		cout << -1;
		return (0);
	}

	res = end - start + 1;
	while (end < n)
	{
		if (v[start] == 1)
			cnt--;
		start++;
		end++;
		if (end < n && v[end] == 1)
			cnt++;
		if (cnt == k)
		{
			while (start < n && v[start] != 1)
				start++;
			if (res > end - start + 1)
				res = end - start + 1;
		}
	}
	cout << res;
}