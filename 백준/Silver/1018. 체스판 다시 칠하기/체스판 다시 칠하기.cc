#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int res;

void	draw(vector<string> v, int y, int x, bool white)
{
	int cnt = 0;

	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if (white == true)
			{
				if ((i + j) % 2 == 0)
				{
					if (v[i][j] != 'W')
						cnt++;
				}
				else if (v[i][j] != 'B')
					cnt++;
			}
			else
			{
				if ((i + j) % 2 == 0)
				{
					if (v[i][j] != 'B')
						cnt++;
				}
				else if (v[i][j] != 'W')
					cnt++;
			}
			if (cnt > res)
				return ;
		}
	}
	res = cnt;
}

int main() {
	fast;
	int n, m;
	cin >> n >> m;
	res = n * m;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			draw(v, i, j, true);
			draw(v, i, j, false);
		}
	}
	cout << res;
}

