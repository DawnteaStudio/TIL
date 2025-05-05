#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;



int main()
{
	fast;
	long long n, a, b;
	cin >> n;
	long long res = 0;
	long long arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		res += b;
		arr[i] = a;
	}
	sort(arr, arr + n);
	for (int i = 1; i <= n; i++)
		res += (arr[i - 1] * i);
	cout << res;
}