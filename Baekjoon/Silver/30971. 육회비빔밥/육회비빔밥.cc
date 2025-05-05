#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int A[10], B[10], C[10], visited[10];
int n, k, res;

void	getvalue(int *arr)
{
	int tmp = 0;

	for (int i = 1; i < n; i++)
	{
		if (C[arr[i - 1]] * C[arr[i]] > k)
		{
			tmp = 0;
			break;
		}
		tmp += (A[arr[i - 1]] * B[arr[i]]);
	}
	if (tmp > res)
		res = tmp;
}

void	getcomb(int depth, int *arr)
{
	if (depth == n)
		getvalue(arr);
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				arr[depth] = i;
				getcomb(depth + 1, arr);
				visited[i] = 0;
			}
		}
	}
}

int main()
{
	fast;
	cin >> n >> k;

	int comb[10];
	for (int i = 0; i < 10; i++)
		comb[i] = -1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
				cin >> A[j];
			else if (i == 1)
				cin >> B[j];
			else
				cin >> C[j];
		}
	}
	getcomb(0, comb);
	if (res)
		cout << res;
	else
		cout << -1;
}