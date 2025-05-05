#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
	fast;
	int n, k, w, v;
	cin >> n >> k;
	int arr[n + 1][k + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (i == 0 || j == 0)
				arr[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> w >> v;
		for (int j = 1; j <= k; j++)
		{
			if (w > j)
				arr[i][j] = arr[i - 1][j];
			else if (v + arr[i - 1][j - w] > arr[i - 1][j])
				arr[i][j] = v + arr[i - 1][j - w];
			else
				arr[i][j] = arr[i - 1][j];
		}
	}
	cout << arr[n][k];
}
