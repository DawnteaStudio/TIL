#include <iostream>
#include <vector>
#include <utility>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int	res = -1;
vector<pair<int, int>>	chicken;
vector<pair<int, int>>	house;

void	find_len(int *arr, int m)
{
	int tmp, tmp_len, tmp_res = 0;

	for (int i = 0; i < house.size(); i++)
	{
		tmp_len = -1;
		for (int j = 0; j < m; j++)
		{
			tmp = abs(chicken[arr[j]].first - house[i].first) + abs(chicken[arr[j]].second - house[i].second);
			if (tmp_len == -1 || tmp_len > tmp)
				tmp_len = tmp;
		}
		tmp_res += tmp_len;
	}
	if (res == -1 || res > tmp_res)
		res = tmp_res;
}

void	backtrack(int *arr, int depth, int m)
{

	if (depth == m)
		find_len(arr, m);
	else
	{
		for (int i = arr[depth - 1] + 1; i < chicken.size(); i++)
		{
			arr[depth] = i;
			backtrack(arr, depth + 1, m);
		}
	}
}

int main()
{
	fast;
	int n, m, tmp;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			if (tmp == 1)
				house.push_back({i, j});
			else if (tmp == 2)
				chicken.push_back({i, j});
		}
	}

	int	arr[m];

	for (int i = 0; i < chicken.size(); i++)
	{
		arr[0] = i;
		backtrack(arr, 1, m);
	}
	cout << res;
}