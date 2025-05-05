#include <iostream>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

bool	comp(int a, int b)
{
	return a > b;
}

int main() {
	fast;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int j, n, r, c, res = 0;
		cin >> j >> n;
		int arr[n];
		for (int k = 0; k < n; k++)
		{
			cin >> r >> c;
			arr[k] = r * c;
		}
		sort(arr, arr + n, comp);
		int tmp = 0;
		while(j > 0)
		{
			j -= arr[tmp];
			tmp++;
			res++;
		}
		cout << res << '\n';
	}
}
