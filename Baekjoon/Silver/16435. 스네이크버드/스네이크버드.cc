#include <iostream>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;

	int n, l;
	cin >> n >> l;
	int arr[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		if (arr[i] <= l)
			l++;
		else
			break;
	}
	cout << l;
}
