#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int	find_ans(int *arr)
{
	sort(arr, arr + 4);
	return (arr[1]);
}

int	find_section(int *arr[], int y, int x, int size)
{
	int res[4];

	if (size == 2)
	{
		int tmp = 0;
		for (int i = y; i < y + size; i++)
		{
			for (int j = x; j < x + size; j++)
			{
				res[tmp] = arr[i][j];
				tmp++;
			}
		}
		return (find_ans(res));
	}
	else
	{
		int	dx[4] = {0, size / 2, 0, size/ 2};
		int dy[4] = {0, 0, size / 2, size / 2};
		for (int i = 0; i < 4; i++)
			res[i] = find_section(arr, y + dy[i], x + dx[i], size / 2);
		return (find_ans(res));
	}
}

int main()
{
	fast;
	int	n;
	cin >> n;
	if (n == 1)
	{
		cin >> n;
		cout << n;
		return (0);
	}
	int answer[4];
	int **tmp = new int*[n];
	for (int i = 0; i < n; i++)
		tmp[i] = new int[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> tmp[i][j];
	}

	int	dx[4] = {0, n / 2, 0, n / 2};
	int dy[4] = {0, 0, n / 2, n / 2};

	if (n == 2)
	{
		int index = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				answer[index] = tmp[i][j]; 
				index++;
			}
		cout << find_ans(answer);
		return (0);
	}
	for (int i = 0; i < 4; i++)
		answer[i] = find_section(tmp, dy[i], dx[i], n / 2);
	cout << find_ans(answer);
}
