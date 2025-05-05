#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
	int n, m, b;
	int res_time = -1, res_floor = -1;
	cin >> n >> m >> b;

	int high = 0, low = 256;
	vector<vector<int> > vec(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> vec[i][j];
			if (vec[i][j] > high)
				high = vec[i][j];
			if (vec[i][j] < low)
				low = vec[i][j];
		}
	}

	for (int i = low; i <= high; i++)
	{
		int tmp = 0;
		int tmp_b = b;

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				tmp_b += vec[j][k] - i;
				if (vec[j][k] - i < 0)
					tmp += i - vec[j][k];
				else
					tmp += (vec[j][k] - i) * 2;
			}
		}
		if (tmp_b >= 0)
		{
			if (res_time == -1 || res_time >= tmp)
			{
				res_time = tmp;
				res_floor = i;
			}
		}
	}
	cout << res_time << " " << res_floor;
}
