#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, res = 0;
	cin >> n;

	if (n == 1)
	{
		cout << 0;
		return (0);
	}
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		int s = 0, e = n - 1;
		while (s < e)
		{
			if (arr[s] + arr[e] == arr[i])
			{
				if (i != s && i != e)
				{
					res++;
					break;
				}
				else if (i == s)
					s++;
				else
					e--;
			}
			else if (arr[s] + arr[e] < arr[i])
				s++;
			else
				e--;
		}
	}
	cout << res;
}
