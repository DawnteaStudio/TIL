#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, m, l;
	cin >> n >> m >> l;
	int arr[n + 1];
	arr[n] = l;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	int index_n, now, mid, cnt, start = 1, end = l;

	while (start <= end)
	{
		mid = (start + end) / 2;
		index_n = 0;
		cnt = 0;
		now = 0;

		while (now < l)
		{
			if (index_n <= n)
			{
				if (arr[index_n] <= now + mid)
				{
					now = arr[index_n];
					index_n++;
				}
				else
				{
					cnt++;
					now += mid;
				}
			}
			else
				break;
		}
		if (cnt <= m)
			end = mid - 1;
		else
			start = mid + 1;
	}
	cout << start;
}