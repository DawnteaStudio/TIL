#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void	is_avail(vector<vector<int> > &v, int start, int city, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (v[city][i] == 1 && v[start][i] == 0)
		{
			v[start][i] = 1;
			is_avail(v, start, i, n);
		}
	}
}

int main()
{
	fast;
	int n, m, tmp;
	cin >> n >> m;
	vector<vector<int> > v(n, vector<int> (n, 0));
	vector<int> routine(m);
	if (n == 1)
	{
		cout << "YES\n";
		return (0);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			if (tmp == 1)
				v[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == 1)
				is_avail(v, i, j, n);
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		routine[i] = tmp - 1;
	}
	for (int i = 1; i < m; i++)
	{
		if (routine[i - 1] == routine[i])
			continue;
		if (v[routine[i - 1]][routine[i]] != 1)
		{
			cout << "NO\n";
			break;
		}
		if (i == m - 1)
			cout << "YES\n";
	}
}