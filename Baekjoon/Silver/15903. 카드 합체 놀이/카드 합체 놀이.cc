#include <iostream>
#include <algorithm>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

long long	n, m;

void	swap(long long *arr, long long a, long long b)
{
	long long tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void	rearrange(long long *arr, long long index)
{
	long long	tmp;

	while ((index << 1) <= n)
	{
		if ((index << 1) + 1 <= n)
			tmp = arr[index << 1] > arr[(index << 1) + 1] ? (index << 1) + 1 : index << 1;
		else
			tmp = index << 1;
		if (arr[index] > arr[tmp])
			swap(arr, tmp, index);
		else
			break;
		index = tmp;
	}
}

void	merge(long long *arr)
{
	long long	second_index;
	if (n >= 3)
		second_index = arr[2] > arr[3] ? 3 : 2;
	else
		second_index = 2;
	long long	value = arr[1] + arr[second_index];
	arr[1] = value;
	arr[second_index] = value;
	rearrange(arr, second_index);
	rearrange(arr, 1);
}

int main()
{
	fast;

	long long res = 0;
	cin >> n >> m;
	long long arr[n + 1];

	arr[0] = 0;
	for (long long i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr, arr + n + 1);

	for (long long i = 0; i < m; i++)
		merge(arr);
	for (long long i = 1; i <= n; i++)
		res += arr[i];
	cout << res;
}
