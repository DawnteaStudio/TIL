#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int n, len, res = 0, cover = 0;
	cin >> n >> len;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		while (arr[i] >= cover)
		{
			cover = arr[i] + len;
			res++;
		}
	}
	cout << res;
}